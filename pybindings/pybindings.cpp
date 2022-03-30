#include <pybind11/pybind11.h>
#include <filter/second_order_reference_model.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pybound_mathlib, m)
{
    py::class_<math::SecondOrderReferenceModel<float>>(m, "SecondOrderReferenceModel")
        .def(py::init<>())
        .def(py::init<const float &, const float &>())
        .def("setParameters", &math::SecondOrderReferenceModel<float>::setParameters)
        .def("getState", &math::SecondOrderReferenceModel<float>::getState)
        .def("getRate", &math::SecondOrderReferenceModel<float>::getRate)
        .def("getAccel", &math::SecondOrderReferenceModel<float>::getAccel)
        .def("update", &math::SecondOrderReferenceModel<float>::update, py::arg("time_step"), py::arg("state_sample"), py::arg("rate_sample") = 0)
        .def("reset", &math::SecondOrderReferenceModel<float>::reset);
}