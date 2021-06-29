#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function<pybind11::module &(std::string const &)> ModuleGetter;

void bind_chip_0(std::function<pybind11::module &(std::string const & namespace_)> & M);
void bind_chip_1(std::function<pybind11::module &(std::string const & namespace_)> & M);
void bind_chip_2(std::function<pybind11::module &(std::string const & namespace_)> & M);
void bind_chip_3(std::function<pybind11::module &(std::string const & namespace_)> & M);
void bind_chip_4(std::function<pybind11::module &(std::string const & namespace_)> & M);
void bind_chip_5(std::function<pybind11::module &(std::string const & namespace_)> & M);

PYBIND11_MODULE(chip, root_module)
{
    root_module.doc() = "chip module";

    std::map<std::string, pybind11::module> modules;
    ModuleGetter M = [&](std::string const & namespace_) -> pybind11::module & {
        auto it = modules.find(namespace_);
        if (it == modules.end())
            throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ +
                                     " before it was created!!!");
        return it->second;
    };

    modules[""] = root_module;

    std::vector<std::pair<std::string, std::string>> sub_modules{
        { "", "chip" },
        { "chip", "Controller" },
        { "chip", "Inet" },
        { "chip", "Transport" },
    };
    for (auto & p : sub_modules)
        modules[p.first.size() ? p.first + "::" + p.second : p.second] =
            modules[p.first].def_submodule(p.second.c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str());

    // pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

    bind_chip_0(M);
    bind_chip_1(M);
    bind_chip_2(M);
    bind_chip_3(M);
    bind_chip_4(M);
    bind_chip_5(M);
}
