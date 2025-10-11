#!/bin/bash

echo "process info:"
ps aux
echo "number of processes $(ps aux | wc -l)"
