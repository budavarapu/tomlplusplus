// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
//-----
// this file was generated by generate_conformance_tests.py - do not modify it directly
// clang-format off

#include "tests.h"
using namespace toml::impl;

TOML_DISABLE_WARNINGS; // unused variable spam

namespace
{
	static constexpr auto array_of_tables_1 = R"(# INVALID TOML DOC
fruit = []

[[fruit]] # Not allowed)"sv;
	static constexpr auto array_of_tables_2 = R"(# INVALID TOML DOC
[[fruit]]
  name = "apple"

  [[fruit.variety]]
    name = "red delicious"

  # This table conflicts with the previous table
  [fruit.variety]
    name = "granny smith")"sv;

	static constexpr auto bare_key_1 = R"(bare!key = 123)"sv;
	static constexpr auto bare_key_2 = R"(barekey
   = 123)"sv;
	static constexpr auto bare_key_3 = R"(barekey =)"sv;

	static constexpr auto inline_table_imutable_1 = R"([product]
type = { name = "Nail" }
type.edible = false  # INVALID)"sv;
	static constexpr auto inline_table_imutable_2 = R"([product]
type.name = "Nail"
type = { edible = false }  # INVALID)"sv;

#if !TOML_LANG_UNRELEASED

	static constexpr auto inline_table_trailing_comma = R"(abc = { abc = 123, })"sv;

#endif // !TOML_LANG_UNRELEASED

	static constexpr auto int_0_padded = R"(int = 0123)"sv;
	static constexpr auto int_signed_bin = R"(bin = +0b10)"sv;
	static constexpr auto int_signed_hex = R"(hex = +0xab)"sv;
	static constexpr auto int_signed_oct = R"(oct = +0o23)"sv;

	static constexpr auto key_value_pair_1 = R"(key = # INVALID)"sv;
	static constexpr auto key_value_pair_2 = R"(first = "Tom" last = "Preston-Werner" # INVALID)"sv;

	static constexpr auto multiple_dot_key = R"(# THE FOLLOWING IS INVALID

# This defines the value of fruit.apple to be an integer.
fruit.apple = 1

# But then this treats fruit.apple like it's a table.
# You can't turn an integer into a table.
fruit.apple.smooth = true)"sv;
	static constexpr auto multiple_key = R"(# DO NOT DO THIS
name = "Tom"
name = "Pradyun")"sv;

	static constexpr auto no_key_name = R"(= "no key name"  # INVALID)"sv;

	static constexpr auto string_basic_multiline_invalid_backslash = R"(a = """
  foo \ \n
  bar""")"sv;
	static constexpr auto string_basic_multiline_out_of_range_unicode_escape_1 = R"(a = """\UFFFFFFFF""")"sv;
	static constexpr auto string_basic_multiline_out_of_range_unicode_escape_2 = R"(a = """\U00D80000""")"sv;
	static constexpr auto string_basic_multiline_quotes = R"(str5 = """Here are three quotation marks: """.""")"sv;
	static constexpr auto string_basic_multiline_unknown_escape = R"(a = """\@""")"sv;
	static constexpr auto string_basic_out_of_range_unicode_escape_1 = R"(a = "\UFFFFFFFF")"sv;
	static constexpr auto string_basic_out_of_range_unicode_escape_2 = R"(a = "\U00D80000")"sv;
	static constexpr auto string_basic_unknown_escape = R"(a = "\@")"sv;
	static constexpr auto string_literal_multiline_quotes = R"(apos15 = '''Here are fifteen apostrophes: ''''''''''''''''''  # INVALID)"sv;

	static constexpr auto table_1 = R"(# DO NOT DO THIS

[fruit]
apple = "red"

[fruit]
orange = "orange")"sv;
	static constexpr auto table_2 = R"(# DO NOT DO THIS EITHER

[fruit]
apple = "red"

[fruit.apple]
texture = "smooth")"sv;
	static constexpr auto table_3 = R"([fruit]
apple.color = "red"
apple.taste.sweet = true

[fruit.apple]  # INVALID)"sv;
	static constexpr auto table_4 = R"([fruit]
apple.color = "red"
apple.taste.sweet = true

[fruit.apple.taste]  # INVALID)"sv;
	static constexpr auto table_invalid_1 = R"([fruit.physical]  # subtable, but to which parent element should it belong?
  color = "red"
  shape = "round"

[[fruit]]  # parser must throw an error upon discovering that "fruit" is
           # an array rather than a table
  name = "apple")"sv;
	static constexpr auto table_invalid_2 = R"(# INVALID TOML DOC
fruit = []

[[fruit]] # Not allowed)"sv;
	static constexpr auto table_invalid_3 = R"(# INVALID TOML DOC
[[fruit]]
  name = "apple"

  [[fruit.variety]]
    name = "red delicious"

  # INVALID: This table conflicts with the previous array of tables
  [fruit.variety]
    name = "granny smith"

  [fruit.physical]
    color = "red"
    shape = "round")"sv;
	static constexpr auto table_invalid_4 = R"(# INVALID TOML DOC
[[fruit]]
  name = "apple"

  [[fruit.variety]]
    name = "red delicious"

  [fruit.physical]
    color = "red"
    shape = "round"

  # INVALID: This array of tables conflicts with the previous table
  [[fruit.physical]]
    color = "green")"sv;
}

TOML_ENABLE_WARNINGS;

TEST_CASE("conformance - iarna/invalid")
{
	parsing_should_fail(FILE_LINE_ARGS, array_of_tables_1); // array-of-tables-1

	parsing_should_fail(FILE_LINE_ARGS, array_of_tables_2); // array-of-tables-2

	parsing_should_fail(FILE_LINE_ARGS, bare_key_1); // bare-key-1

	parsing_should_fail(FILE_LINE_ARGS, bare_key_2); // bare-key-2

	parsing_should_fail(FILE_LINE_ARGS, bare_key_3); // bare-key-3

	parsing_should_fail(FILE_LINE_ARGS, inline_table_imutable_1); // inline-table-imutable-1

	parsing_should_fail(FILE_LINE_ARGS, inline_table_imutable_2); // inline-table-imutable-2

#if !TOML_LANG_UNRELEASED

	parsing_should_fail(FILE_LINE_ARGS, inline_table_trailing_comma); // inline-table-trailing-comma

#endif // !TOML_LANG_UNRELEASED

	parsing_should_fail(FILE_LINE_ARGS, int_0_padded); // int-0-padded

	parsing_should_fail(FILE_LINE_ARGS, int_signed_bin); // int-signed-bin

	parsing_should_fail(FILE_LINE_ARGS, int_signed_hex); // int-signed-hex

	parsing_should_fail(FILE_LINE_ARGS, int_signed_oct); // int-signed-oct

	parsing_should_fail(FILE_LINE_ARGS, key_value_pair_1); // key-value-pair-1

	parsing_should_fail(FILE_LINE_ARGS, key_value_pair_2); // key-value-pair-2

	parsing_should_fail(FILE_LINE_ARGS, multiple_dot_key); // multiple-dot-key

	parsing_should_fail(FILE_LINE_ARGS, multiple_key); // multiple-key

	parsing_should_fail(FILE_LINE_ARGS, no_key_name); // no-key-name

	parsing_should_fail(FILE_LINE_ARGS, string_basic_multiline_invalid_backslash); // string-basic-multiline-invalid-backslash

	parsing_should_fail(FILE_LINE_ARGS, string_basic_multiline_out_of_range_unicode_escape_1); // string-basic-multiline-out-of-range-unicode-escape-1

	parsing_should_fail(FILE_LINE_ARGS, string_basic_multiline_out_of_range_unicode_escape_2); // string-basic-multiline-out-of-range-unicode-escape-2

	parsing_should_fail(FILE_LINE_ARGS, string_basic_multiline_quotes); // string-basic-multiline-quotes

	parsing_should_fail(FILE_LINE_ARGS, string_basic_multiline_unknown_escape); // string-basic-multiline-unknown-escape

	parsing_should_fail(FILE_LINE_ARGS, string_basic_out_of_range_unicode_escape_1); // string-basic-out-of-range-unicode-escape-1

	parsing_should_fail(FILE_LINE_ARGS, string_basic_out_of_range_unicode_escape_2); // string-basic-out-of-range-unicode-escape-2

	parsing_should_fail(FILE_LINE_ARGS, string_basic_unknown_escape); // string-basic-unknown-escape

	parsing_should_fail(FILE_LINE_ARGS, string_literal_multiline_quotes); // string-literal-multiline-quotes

	parsing_should_fail(FILE_LINE_ARGS, table_1); // table-1

	parsing_should_fail(FILE_LINE_ARGS, table_2); // table-2

	parsing_should_fail(FILE_LINE_ARGS, table_3); // table-3

	parsing_should_fail(FILE_LINE_ARGS, table_4); // table-4

	parsing_should_fail(FILE_LINE_ARGS, table_invalid_1); // table-invalid-1

	parsing_should_fail(FILE_LINE_ARGS, table_invalid_2); // table-invalid-2

	parsing_should_fail(FILE_LINE_ARGS, table_invalid_3); // table-invalid-3

	parsing_should_fail(FILE_LINE_ARGS, table_invalid_4); // table-invalid-4
}

