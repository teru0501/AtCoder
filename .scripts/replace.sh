#!/usr/bin/env bash

echo -e "\033[1;34m>>REPLACE\033[0m"

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
{ head -n 1 "$1"; cat "$SCRIPT_DIR/../.templates/template.cpp"; } > "$1.tmp" \
&& mv "$1.tmp" "$1" || echo -1
