/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_MBOX_H
#define Z_INCLUDE_SYSCALLS_MBOX_H


#include <zephyr/tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <stdarg.h>

#include <syscall_list.h>
#include <zephyr/syscall.h>

#include <zephyr/linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_mbox_send(const struct device * dev, mbox_channel_id_t channel_id, const struct mbox_msg * msg);

__pinned_func
static inline int mbox_send(const struct device * dev, mbox_channel_id_t channel_id, const struct mbox_msg * msg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; mbox_channel_id_t val; } parm1 = { .val = channel_id };
		union { uintptr_t x; const struct mbox_msg * val; } parm2 = { .val = msg };
		return (int) arch_syscall_invoke3(parm0.x, parm1.x, parm2.x, K_SYSCALL_MBOX_SEND);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_send(dev, channel_id, msg);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_send(dev, channel_id, msg) ({ 	int syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_SEND, mbox_send, dev, channel_id, msg); 	syscall__retval = mbox_send(dev, channel_id, msg); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_SEND, mbox_send, dev, channel_id, msg, syscall__retval); 	syscall__retval; })
#endif
#endif


extern int z_impl_mbox_mtu_get(const struct device * dev);

__pinned_func
static inline int mbox_mtu_get(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		return (int) arch_syscall_invoke1(parm0.x, K_SYSCALL_MBOX_MTU_GET);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_mtu_get(dev);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_mtu_get(dev) ({ 	int syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_MTU_GET, mbox_mtu_get, dev); 	syscall__retval = mbox_mtu_get(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_MTU_GET, mbox_mtu_get, dev, syscall__retval); 	syscall__retval; })
#endif
#endif


extern int z_impl_mbox_set_enabled(const struct device * dev, mbox_channel_id_t channel_id, bool enabled);

__pinned_func
static inline int mbox_set_enabled(const struct device * dev, mbox_channel_id_t channel_id, bool enabled)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; mbox_channel_id_t val; } parm1 = { .val = channel_id };
		union { uintptr_t x; bool val; } parm2 = { .val = enabled };
		return (int) arch_syscall_invoke3(parm0.x, parm1.x, parm2.x, K_SYSCALL_MBOX_SET_ENABLED);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_set_enabled(dev, channel_id, enabled);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_set_enabled(dev, channel_id, enabled) ({ 	int syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_SET_ENABLED, mbox_set_enabled, dev, channel_id, enabled); 	syscall__retval = mbox_set_enabled(dev, channel_id, enabled); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_SET_ENABLED, mbox_set_enabled, dev, channel_id, enabled, syscall__retval); 	syscall__retval; })
#endif
#endif


extern uint32_t z_impl_mbox_max_channels_get(const struct device * dev);

__pinned_func
static inline uint32_t mbox_max_channels_get(const struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		return (uint32_t) arch_syscall_invoke1(parm0.x, K_SYSCALL_MBOX_MAX_CHANNELS_GET);
	}
#endif
	compiler_barrier();
	return z_impl_mbox_max_channels_get(dev);
}

#if defined(CONFIG_TRACING_SYSCALL)
#ifndef DISABLE_SYSCALL_TRACING

#define mbox_max_channels_get(dev) ({ 	uint32_t syscall__retval; 	sys_port_trace_syscall_enter(K_SYSCALL_MBOX_MAX_CHANNELS_GET, mbox_max_channels_get, dev); 	syscall__retval = mbox_max_channels_get(dev); 	sys_port_trace_syscall_exit(K_SYSCALL_MBOX_MAX_CHANNELS_GET, mbox_max_channels_get, dev, syscall__retval); 	syscall__retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */
