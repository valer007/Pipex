#!/bin/bash

# Check if the user passed a command name
if [ -z "$1" ]; then
  echo "Usage: $0 <command_name>"
  exit 1
fi

# Get the full path using 'command -v'
CMD_PATH=$(command -v "$1")

# Check if the command exists
if [ -z "$CMD_PATH" ]; then
  echo "Command '$1' not found."
  exit 2
else
  echo "Full path of '$1': $CMD_PATH"
fi