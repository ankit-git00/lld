#!/usr/bin/env bash
set -euo pipefail
# Simple build+run helper for this project
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
SRC="$ROOT_DIR/src"
OUT="$ROOT_DIR/out"
MAIN="${1:-pubsub.entities.Message}"

echo "Compiling Java sources from $SRC to $OUT..."
mkdir -p "$OUT"
# collect files into a temp file to avoid command-line length issues
TMP_FILES=$(mktemp)
find "$SRC" -name "*.java" > "$TMP_FILES"
javac -d "$OUT" @"$TMP_FILES"
rm -f "$TMP_FILES"

echo "Running $MAIN"
java -cp "$OUT" "$MAIN"
