import os
import re

class ErrorCode(object):
    def __init__(self, error_name, error_code, min_error_code):
        self.name = error_name.replace('_',' ').title().replace(' ','')
        self.message = error_name
        self.code = int(error_code) + min_error_code
    
    def __str__(self):
        return '<ErrorCode name="{}" code="{}">'.format(self.name, self.code)
    
    def __repr__(self):
        return '<ErrorCode name="{}" code={}>'.format(self.name, self.code)
    
    def create_exception_class(self):
        return '''
struct <name> : public std::exception
{
    const char * what () const throw ()
    {
    	return "<message>";
    }
};
'''.replace('<name>',self.name).replace('<message>',self.message)

    def create_py_bind(self, module_name):
        return 'py::register_exception<{}>({}, "{}");'.format(self.name, module_name, self.name)
    
    def create_else_if(self, var_name):
        return '''
    else if (<var_name> == <error_code>) {
        throw <name>()
    }'''.replace('<var_name>',var_name).replace('<error_code>',str(self.code)).replace('<name>',self.name)

def generate_header(error_codes):
    structs = "".join([x.create_exception_class() for x in error_codes])
    return '''
#include <exception>

namespace chip {
namespace PythonBindings {
<structs>

void CHIPErrorToException(CHIP_ERROR err);
}
}

'''.replace('<structs>',structs)

def generate_cpp(error_codes):
    exception_binding = '\n\t'.join([x.create_py_bind('m') for x in error_codes])
    elseifs = ''.join([x.create_else_if('err') for x in error_codes])
    return '''
#include "pybind11/pybind11.h"
#include "CHIPErrorBindings.h"

namespace py = pybind11;

void CHIPErrorToException(CHIP_ERROR err) {
    if err == CHIP_NO_ERR {
        //Do Nothing
    }<elseifs>
}

PYBIND11_MODULE(CHIPException, m) {
    m.def("CHIPErrorToException", &CHIPErrorToException, "Converts a CHIP_ERROR (int) to an Exception")

    <exception_binding>
}
'''.replace('<exception_binding>',exception_binding).replace('<elseifs>',elseifs)

ERROR_PATH = '../../lib/core/CHIPError.h'
CONFIG_PATH = '../../lib/core/CHIPConfig.h'

error_header = None
config_header = None

with open(ERROR_PATH, 'r') as f:
    error_header = f.read()

with open(CONFIG_PATH, 'r') as f:
    config_header = f.read()

if error_header != None and config_header != None:
    min_err_re = re.compile(r'CHIP_CONFIG_ERROR_MIN (\d+)')
    matches = min_err_re.findall(config_header)

    min_err = -1

    if len(matches) >= 1:
        min_err = int(matches[0])

    if min_err != -1:
        error_code_re = re.compile(r'#define (\S+).*_CHIP_ERROR\((\d+)\)')
        error_code_tuples = error_code_re.findall(error_header)
        error_codes = [ErrorCode(x[0],x[1], min_err) for x in error_code_tuples]
        header = generate_header(error_codes)

        with open('CHIPErrorToExceptionBindings.h', 'w') as f:
            f.write(header)
        
        cpp = generate_cpp(error_codes)

        with open('CHIPErrorToExceptionBindings.cpp', 'w') as f:
            f.write(cpp)