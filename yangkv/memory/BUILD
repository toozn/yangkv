cc_library(
    name = "message",
    srcs = ["message.cpp"],
    hdrs = ["message.h"],
    visibility = ["//__pkg__"],
)

cc_library(
    name = "message_queue",
    srcs = ["message_queue.cpp"],
    hdrs = ["message_queue.h"],
    deps = [":message"],
    visibility = ["//__pkg__"],
)

cc_library(
	name = "skip_list",
    srcs = ["skip_list.cpp"],
    hdrs = ["skip_list.h"],
    deps = [":message_queue"],
    visibility = ["//main:__pkg__"],
)
