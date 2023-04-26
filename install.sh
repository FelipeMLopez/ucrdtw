#!/bin/bash

# Get the hostname of the server
HOSTNAME=$(hostname)

# Check the hostname and install the appropriate library
if [ "$HOSTNAME" == "alder" ]; then
    # Install library for server1
    pip install --upgrade --target=$HOME/venv/lib/python3.8/site-packages .
    pip install --upgrade --target=$HOME/.conda/envs/fmlopez_intelpython/lib/python3.9/site-packages/ .
elif [ "$HOSTNAME" == "picasso" ]; then
    # Install library for server2
    pip install --upgrade --target=$HOME/venv/lib/python3.8/site-packages .
else
    echo "Unknown server"
fi

# python setup.py build && python setup.py install --install-lib ../venv/lib/python3.9/site-packages/
# pip install --upgrade --target=$HOME/venv/lib/python3.8/site-packages .
# pip install --upgrade --target=/opt/intel/oneapi/intelpython/python3.9/envs/2022.2.1/lib/python3.9/site-packages .