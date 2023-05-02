from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

cpp_args = ['-std=c++17', '-O3']

ext_modules = [
    Pybind11Extension(
        "ucrdtwbind",
        sorted(glob("*.cpp")),  # Sort source files for reproducibility
        extra_compile_args = cpp_args,
    ),
]

setup(
    name='ucrdtwbind',
    version='0.0.1',
    author='Rafael Asenjo',
    author_email='asenjo@uma.es',
    description='UCR DTW function',
    ext_modules=ext_modules,
)