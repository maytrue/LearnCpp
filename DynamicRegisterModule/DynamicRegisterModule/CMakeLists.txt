add_executable(
    dyname_register_module
    main.c
    Module.c
    ModuleA.c
    ModuleB.c
    ModuleC.c
)

# target_link_libraries(thread_safe_singleton Threads::Threads)
