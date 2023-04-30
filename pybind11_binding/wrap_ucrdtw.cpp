#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "ucrdtw.h"

namespace py = pybind11;
using namespace pybind11::literals;


std::pair<int64_t,double> wrap_ucrdtw (const py::array_t<double> &data, const py::array_t<double> &query, 
                                     double warp_width, bool verbose,
                                     const py::array_t <int32_t> &dnc) {

    long long location = -1;
    double distance = -1;

    const double *internal_data = data.data();
    const double *internal_query = query.data();
    const int32_t *internal_dnc = dnc.data();
    int32_t verbose_int = verbose ? 1 : 0;

    int status = ucrdtw(internal_data, data.size(), 
                        internal_query, query.size(), 
                        warp_width, verbose_int, &location, &distance, internal_dnc);
    if(status != 0) {
        throw std::runtime_error("ucrdtw failed");
    }
    return std::make_pair(location, distance);
}

std::pair<int64_t,double> wrap_ucrdtws (const py::array_t<double> &data, const py::array_t<double> &query, 
                                     double warp_width, bool verbose,
                                     const py::array_t <int32_t> &dnc, int32_t stride) {

    long long location = -1;
    double distance = -1;

    const double *internal_data = data.data();
    const double *internal_query = query.data();
    const int32_t *internal_dnc = dnc.data();
    int32_t verbose_int = verbose ? 1 : 0;

    int status = ucrdtws(internal_data, data.size(), 
                        internal_query, query.size(), 
                        warp_width, verbose_int, &location, &distance, internal_dnc, stride);
    if(status != 0) {
        throw std::runtime_error("ucrdtw failed");
    }
    return std::make_pair(location, distance);
}

PYBIND11_MODULE(ucrdtw, m) {
    m.doc() = "UCR DTW module";

    m.def("ucrdtw", &wrap_ucrdtw, "A function which computes the UCR DTW distance between two time series",
          py::arg("data"),
          py::arg("query"),
          py::arg("warp_width"),
          py::arg("verbose"),
          py::arg("dnc"));
          
    m.def("ucrdtws", &wrap_ucrdtws, "A function which computes the UCR DTW distance between two time series with a stride",
          py::arg("data"),
          py::arg("query"),
          py::arg("warp_width"),
          py::arg("verbose"),
          py::arg("dnc"),
          py::arg("stride"));

}