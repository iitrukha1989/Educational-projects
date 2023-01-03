from setuptools import setup, Extension

setup(
    name="calculator",
    ext_modules=[
        Extension('calculator', sources=["calculator.c"])
    ])
