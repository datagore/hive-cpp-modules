#! /usr/bin/bash

test() {
    echo -e "\n\e[36m./convert $1\e[0m ($2)"
    ./convert $1
}

section() {
    echo -e "\n\e[1;33m=============== $1 ===============\e[0m"
}

section "INTEGER TESTS"
test "0" "integer zero"
test "12345" "positive integer"
test "-112233" "negative integer"
test "2147483647" "INT_MAX"
test "2147483648" "INT_MAX + 1"
test "-2147483648" "INT_MIN"
test "-2147483649" "INT_MIN - 1"
test "100000000000000000" "huge integer"

section "CHARACTER TESTS"
test "0" "ASCII null character"
test "!" "ASCII exclamation point"
test "a" "ASCII A"
test "~" "ASCII tilde"
test "127" "ASCII delete character"

section "DOUBLE TESTS"
test "42.5" "double with decimals"
test ".125" "double with no integer part"
test "nan" "double NaN"
test "inf" "double infinity"
test "-inf" "double negative infinity"

section "FLOAT TESTS"
test ".125f" "float with no integer part"
test "nanf" "float NaN"
test "inff" "float infinity"
test "-inff" "float negative infinity"

section "INVALID INPUTS"
test "" "empty string"
test "hello" "no digits"
test "123abc" "trailing nondigits"
test "--123" "multiple negative signs"
test "1.2.3" "multiple decimal points"
test "123f" "float without decimal point"
