#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
{ head -n 1 "$1"; cat "$SCRIPT_DIR/../.templates/template.cpp"; } > "$1.tmp" \
&& mv "$1.tmp" "$1" || echo -1
