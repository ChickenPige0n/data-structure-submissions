add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")
set_runtimes("MT")
set_toolchains("clang")

set_languages("c23")

target("project")
    add_cflags("-Wno-deprecated-declarations")
    set_kind("binary")
    add_files("*.c")