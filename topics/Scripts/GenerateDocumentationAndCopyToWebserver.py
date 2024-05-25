import subprocess
import os
import shutil

# Generate and copy documentation to webserver
# Script is run in build folder on build server

def generate_documentation_and_copy_to_webserver():

    #Get tools
    cmake_dir = "C:\\Tools\\cmake\\bin"
    graph_viz = "D:\\Tools\\graphviz-2.38\\release\\bin SET PATH=%PATH%;D:\\Tools\\graphviz-2.38\\release\\bin"

    #Build Doxygen
    print("Generating Doxygen")
    subprocess.run(cmake_dir + '\\cmake --build . --target Documentation')

if __name__ == "__main__":
    generate_documentation_and_copy_to_webserver()
