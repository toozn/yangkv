cc_library(
    name = "singleton",
    srcs = ["singleton.cpp"],
    hdrs = ["singleton.h"],
    deps = [":yangkvMain"]
)

cc_library(
    name = "yangkvMain",
    srcs = ["yangkvMain.cpp"],
    hdrs = ["yangkvMain.h"],
    deps = ["//memory:skip_list", 
            "//utils:env",
            "//utils:hashhelper",
           ],
)

cc_binary(
	name = "test",
	srcs = ["test.cpp"],
	deps = [":singleton"],
	linkopts = [
        "-pthread",
    ],
)
