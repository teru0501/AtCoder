#!/usr/bin/env bash

echo -e "\033[1;34m>>REPLACE\033[0m"

TARGET="$1"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEMPLATE="$SCRIPT_DIR/../.templates/template.cpp"

# 引数チェック
if [ -z "$TARGET" ] || [ ! -f "$TARGET" ]; then
  echo "invalid target" >&2
  exit 1
fi

code --command workbench.action.closeActiveEditor

# 置換処理
{
  head -n 1 "$TARGET"
  cat "$TEMPLATE"
} > "$TARGET.tmp" \
&& mv "$TARGET.tmp" "$TARGET" || { echo -1; exit 1; }

# 再度開く
code --goto "$TARGET:53:3"
