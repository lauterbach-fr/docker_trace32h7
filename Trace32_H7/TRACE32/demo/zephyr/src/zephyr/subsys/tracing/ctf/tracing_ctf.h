/*
 * Copyright (c) 2018 Oticon A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _TRACE_CTF_H
#define _TRACE_CTF_H

#include <zephyr/kernel.h>
#include <zephyr/kernel_structs.h>
#include <zephyr/init.h>

#ifdef __cplusplus
extern "C" {
#endif


#define sys_port_trace_k_thread_foreach_enter()
#define sys_port_trace_k_thread_foreach_exit()
#define sys_port_trace_k_thread_foreach_unlocked_enter()
#define sys_port_trace_k_thread_foreach_unlocked_exit()

#define sys_port_trace_k_thread_create(new_thread)                             \
	sys_trace_k_thread_create(new_thread, stack_size, prio)

#define sys_port_trace_k_thread_user_mode_enter()                              \
	sys_trace_k_thread_user_mode_enter(entry, p1, p2, p3)

#define sys_port_trace_k_thread_heap_assign(thread, heap)
#define sys_port_trace_k_thread_join_enter(thread, timeout)
#define sys_port_trace_k_thread_join_blocking(thread, timeout)
#define sys_port_trace_k_thread_join_exit(thread, timeout, ret)
#define sys_port_trace_k_thread_sleep_enter(timeout)
#define sys_port_trace_k_thread_sleep_exit(timeout, ret)
#define sys_port_trace_k_thread_msleep_enter(ms)
#define sys_port_trace_k_thread_msleep_exit(ms, ret)
#define sys_port_trace_k_thread_usleep_enter(us)
#define sys_port_trace_k_thread_usleep_exit(us, ret)
#define sys_port_trace_k_thread_busy_wait_enter(usec_to_wait)
#define sys_port_trace_k_thread_busy_wait_exit(usec_to_wait)
#define sys_port_trace_k_thread_yield()
#define sys_port_trace_k_thread_wakeup(thread) sys_trace_k_thread_wakeup(thread)
#define sys_port_trace_k_thread_start(thread) sys_trace_k_thread_start(thread)
#define sys_port_trace_k_thread_abort(thread) sys_trace_k_thread_abort(thread)
#define sys_port_trace_k_thread_suspend_enter(thread)                          \
	sys_trace_k_thread_suspend(thread)
#define sys_port_trace_k_thread_suspend_exit(thread)
#define sys_port_trace_k_thread_resume_enter(thread)                           \
	sys_trace_k_thread_resume(thread)

#define sys_port_trace_k_thread_sched_lock()

#define sys_port_trace_k_thread_sched_unlock()

#define sys_port_trace_k_thread_name_set(thread, ret)                          \
	sys_trace_k_thread_name_set(thread, ret)

#define sys_port_trace_k_thread_switched_out() sys_trace_k_thread_switched_out()

#define sys_port_trace_k_thread_switched_in() sys_trace_k_thread_switched_in()

#define sys_port_trace_k_thread_info(thread) sys_trace_k_thread_info(thread)

#define sys_port_trace_k_thread_sched_wakeup(thread)
#define sys_port_trace_k_thread_sched_abort(thread)
#define sys_port_trace_k_thread_sched_priority_set(thread, prio)
#define sys_port_trace_k_thread_sched_ready(thread)

#define sys_port_trace_k_thread_sched_pend(thread)

#define sys_port_trace_k_thread_sched_resume(thread)

#define sys_port_trace_k_thread_sched_suspend(thread)

#define sys_port_trace_k_work_init(work)
#define sys_port_trace_k_work_submit_to_queue_enter(queue, work)
#define sys_port_trace_k_work_submit_to_queue_exit(queue, work, ret)
#define sys_port_trace_k_work_submit_enter(work)
#define sys_port_trace_k_work_submit_exit(work, ret)
#define sys_port_trace_k_work_flush_enter(work)
#define sys_port_trace_k_work_flush_blocking(work, timeout)
#define sys_port_trace_k_work_flush_exit(work, ret)
#define sys_port_trace_k_work_cancel_enter(work)
#define sys_port_trace_k_work_cancel_exit(work, ret)
#define sys_port_trace_k_work_cancel_sync_enter(work, sync)
#define sys_port_trace_k_work_cancel_sync_blocking(work, sync)
#define sys_port_trace_k_work_cancel_sync_exit(work, sync, ret)

#define sys_port_trace_k_work_queue_init(queue)
#define sys_port_trace_k_work_queue_start_enter(queue)
#define sys_port_trace_k_work_queue_start_exit(queue)
#define sys_port_trace_k_work_queue_drain_enter(queue)
#define sys_port_trace_k_work_queue_drain_exit(queue, ret)
#define sys_port_trace_k_work_queue_unplug_enter(queue)
#define sys_port_trace_k_work_queue_unplug_exit(queue, ret)

#define sys_port_trace_k_work_delayable_init(dwork)
#define sys_port_trace_k_work_schedule_for_queue_enter(queue, dwork, delay)
#define sys_port_trace_k_work_schedule_for_queue_exit(queue, dwork, delay,     \
						      ret)
#define sys_port_trace_k_work_schedule_enter(dwork, delay)
#define sys_port_trace_k_work_schedule_exit(dwork, delay, ret)
#define sys_port_trace_k_work_reschedule_for_queue_enter(queue, dwork, delay)
#define sys_port_trace_k_work_reschedule_for_queue_exit(queue, dwork, delay,   \
							ret)
#define sys_port_trace_k_work_reschedule_enter(dwork, delay)
#define sys_port_trace_k_work_reschedule_exit(dwork, delay, ret)
#define sys_port_trace_k_work_flush_delayable_enter(dwork, sync)
#define sys_port_trace_k_work_flush_delayable_exit(dwork, sync, ret)
#define sys_port_trace_k_work_cancel_delayable_enter(dwork)
#define sys_port_trace_k_work_cancel_delayable_exit(dwork, ret)
#define sys_port_trace_k_work_cancel_delayable_sync_enter(dwork, sync)
#define sys_port_trace_k_work_cancel_delayable_sync_exit(dwork, sync, ret)

#define sys_port_trace_k_work_poll_init_enter(work)
#define sys_port_trace_k_work_poll_init_exit(work)
#define sys_port_trace_k_work_poll_submit_to_queue_enter(work_q, work,         \
							 timeout)
#define sys_port_trace_k_work_poll_submit_to_queue_blocking(work_q, work,      \
							    timeout)
#define sys_port_trace_k_work_poll_submit_to_queue_exit(work_q, work, timeout, \
							ret)
#define sys_port_trace_k_work_poll_submit_enter(work, timeout)
#define sys_port_trace_k_work_poll_submit_exit(work, timeout, ret)
#define sys_port_trace_k_work_poll_cancel_enter(work)
#define sys_port_trace_k_work_poll_cancel_exit(work, ret)

#define sys_port_trace_k_poll_api_event_init(event)
#define sys_port_trace_k_poll_api_poll_enter(events)
#define sys_port_trace_k_poll_api_poll_exit(events, ret)
#define sys_port_trace_k_poll_api_signal_init(signal)
#define sys_port_trace_k_poll_api_signal_reset(signal)
#define sys_port_trace_k_poll_api_signal_check(signal)
#define sys_port_trace_k_poll_api_signal_raise(signal, ret)

#define sys_port_trace_k_sem_init(sem, ret)                                    \
	sys_trace_k_sem_init(sem, ret)

#define sys_port_trace_k_sem_give_enter(sem) sys_trace_k_sem_give_enter(sem)
#define sys_port_trace_k_sem_give_exit(sem) sys_trace_k_sem_give_exit(sem)
#define sys_port_trace_k_sem_take_enter(sem, timeout)                          \
	sys_trace_k_sem_take_enter(sem, timeout)
#define sys_port_trace_k_sem_take_blocking(sem, timeout)                       \
	sys_trace_k_sem_take_blocking(sem, timeout)
#define sys_port_trace_k_sem_take_exit(sem, timeout, ret)                      \
	sys_trace_k_sem_take_exit(sem, timeout, ret)
#define sys_port_trace_k_sem_reset(sem) sys_trace_k_sem_reset(sem)

#define sys_port_trace_k_mutex_init(mutex, ret)                                \
	sys_trace_k_mutex_init(mutex, ret)
#define sys_port_trace_k_mutex_lock_enter(mutex, timeout)                      \
	sys_trace_k_mutex_lock_enter(mutex, timeout)
#define sys_port_trace_k_mutex_lock_blocking(mutex, timeout)                   \
	sys_trace_k_mutex_lock_blocking(mutex, timeout)
#define sys_port_trace_k_mutex_lock_exit(mutex, timeout, ret)                  \
	sys_trace_k_mutex_lock_exit(mutex, timeout, ret)
#define sys_port_trace_k_mutex_unlock_enter(mutex)                             \
	sys_trace_k_mutex_unlock_enter(mutex)
#define sys_port_trace_k_mutex_unlock_exit(mutex, ret)                         \
	sys_trace_k_mutex_unlock_exit(mutex, ret)

/* Timer */
#define sys_port_trace_k_timer_init(timer)					\
	sys_trace_k_timer_init(timer)
#define sys_port_trace_k_timer_start(timer, duration, period)			\
	sys_trace_k_timer_start(timer, duration, period)
#define sys_port_trace_k_timer_stop(timer)					\
	sys_trace_k_timer_stop(timer)
#define sys_port_trace_k_timer_status_sync_enter(timer)				\
	sys_trace_k_timer_status_sync_enter(timer)
#define sys_port_trace_k_timer_status_sync_blocking(timer, timeout)		\
	sys_trace_k_timer_status_sync_blocking(timer, timeout)
#define sys_port_trace_k_timer_status_sync_exit(timer, result)			\
	sys_trace_k_timer_status_sync_exit(timer, result)


#define sys_port_trace_k_condvar_init(condvar, ret)
#define sys_port_trace_k_condvar_signal_enter(condvar)
#define sys_port_trace_k_condvar_signal_blocking(condvar, timeout)
#define sys_port_trace_k_condvar_signal_exit(condvar, ret)
#define sys_port_trace_k_condvar_broadcast_enter(condvar)
#define sys_port_trace_k_condvar_broadcast_exit(condvar, ret)
#define sys_port_trace_k_condvar_wait_enter(condvar)
#define sys_port_trace_k_condvar_wait_exit(condvar, ret)

#define sys_port_trace_k_queue_init(queue)
#define sys_port_trace_k_queue_cancel_wait(queue)
#define sys_port_trace_k_queue_queue_insert_enter(queue, alloc)
#define sys_port_trace_k_queue_queue_insert_blocking(queue, alloc, timeout)
#define sys_port_trace_k_queue_queue_insert_exit(queue, alloc, ret)
#define sys_port_trace_k_queue_append_enter(queue)
#define sys_port_trace_k_queue_append_exit(queue)
#define sys_port_trace_k_queue_alloc_append_enter(queue)
#define sys_port_trace_k_queue_alloc_append_exit(queue, ret)
#define sys_port_trace_k_queue_prepend_enter(queue)
#define sys_port_trace_k_queue_prepend_exit(queue)
#define sys_port_trace_k_queue_alloc_prepend_enter(queue)
#define sys_port_trace_k_queue_alloc_prepend_exit(queue, ret)
#define sys_port_trace_k_queue_insert_enter(queue)
#define sys_port_trace_k_queue_insert_blocking(queue, timeout)
#define sys_port_trace_k_queue_insert_exit(queue)
#define sys_port_trace_k_queue_append_list_enter(queue)
#define sys_port_trace_k_queue_append_list_exit(queue, ret)
#define sys_port_trace_k_queue_merge_slist_enter(queue)
#define sys_port_trace_k_queue_merge_slist_exit(queue, ret)
#define sys_port_trace_k_queue_get_enter(queue, timeout)
#define sys_port_trace_k_queue_get_blocking(queue, timeout)
#define sys_port_trace_k_queue_get_exit(queue, timeout, ret)
#define sys_port_trace_k_queue_remove_enter(queue)
#define sys_port_trace_k_queue_remove_exit(queue, ret)
#define sys_port_trace_k_queue_unique_append_enter(queue)
#define sys_port_trace_k_queue_unique_append_exit(queue, ret)
#define sys_port_trace_k_queue_peek_head(queue, ret)
#define sys_port_trace_k_queue_peek_tail(queue, ret)

#define sys_port_trace_k_fifo_init_enter(fifo)
#define sys_port_trace_k_fifo_init_exit(fifo)
#define sys_port_trace_k_fifo_cancel_wait_enter(fifo)
#define sys_port_trace_k_fifo_cancel_wait_exit(fifo)
#define sys_port_trace_k_fifo_put_enter(fifo, data)
#define sys_port_trace_k_fifo_put_exit(fifo, data)
#define sys_port_trace_k_fifo_alloc_put_enter(fifo, data)
#define sys_port_trace_k_fifo_alloc_put_exit(fifo, data, ret)
#define sys_port_trace_k_fifo_put_list_enter(fifo, head, tail)
#define sys_port_trace_k_fifo_put_list_exit(fifo, head, tail)
#define sys_port_trace_k_fifo_put_slist_enter(fifo, list)
#define sys_port_trace_k_fifo_put_slist_exit(fifo, list)
#define sys_port_trace_k_fifo_get_enter(fifo, timeout)
#define sys_port_trace_k_fifo_get_exit(fifo, timeout, ret)
#define sys_port_trace_k_fifo_peek_head_enter(fifo)
#define sys_port_trace_k_fifo_peek_head_exit(fifo, ret)
#define sys_port_trace_k_fifo_peek_tail_enter(fifo)
#define sys_port_trace_k_fifo_peek_tail_exit(fifo, ret)

#define sys_port_trace_k_lifo_init_enter(lifo)
#define sys_port_trace_k_lifo_init_exit(lifo)
#define sys_port_trace_k_lifo_put_enter(lifo, data)
#define sys_port_trace_k_lifo_put_exit(lifo, data)
#define sys_port_trace_k_lifo_alloc_put_enter(lifo, data)
#define sys_port_trace_k_lifo_alloc_put_exit(lifo, data, ret)
#define sys_port_trace_k_lifo_get_enter(lifo, timeout)
#define sys_port_trace_k_lifo_get_exit(lifo, timeout, ret)

#define sys_port_trace_k_stack_init(stack)
#define sys_port_trace_k_stack_alloc_init_enter(stack)
#define sys_port_trace_k_stack_alloc_init_exit(stack, ret)
#define sys_port_trace_k_stack_cleanup_enter(stack)
#define sys_port_trace_k_stack_cleanup_exit(stack, ret)
#define sys_port_trace_k_stack_push_enter(stack)
#define sys_port_trace_k_stack_push_exit(stack, ret)
#define sys_port_trace_k_stack_pop_enter(stack, timeout)
#define sys_port_trace_k_stack_pop_blocking(stack, timeout)
#define sys_port_trace_k_stack_pop_exit(stack, timeout, ret)

#define sys_port_trace_k_msgq_init(msgq)
#define sys_port_trace_k_msgq_alloc_init_enter(msgq)
#define sys_port_trace_k_msgq_alloc_init_exit(msgq, ret)
#define sys_port_trace_k_msgq_cleanup_enter(msgq)
#define sys_port_trace_k_msgq_cleanup_exit(msgq, ret)
#define sys_port_trace_k_msgq_put_enter(msgq, timeout)
#define sys_port_trace_k_msgq_put_blocking(msgq, timeout)
#define sys_port_trace_k_msgq_put_exit(msgq, timeout, ret)
#define sys_port_trace_k_msgq_get_enter(msgq, timeout)
#define sys_port_trace_k_msgq_get_blocking(msgq, timeout)
#define sys_port_trace_k_msgq_get_exit(msgq, timeout, ret)
#define sys_port_trace_k_msgq_peek(msgq, ret)
#define sys_port_trace_k_msgq_purge(msgq)

#define sys_port_trace_k_mbox_init(mbox)
#define sys_port_trace_k_mbox_message_put_enter(mbox, timeout)
#define sys_port_trace_k_mbox_message_put_blocking(mbox, timeout)
#define sys_port_trace_k_mbox_message_put_exit(mbox, timeout, ret)
#define sys_port_trace_k_mbox_put_enter(mbox, timeout)
#define sys_port_trace_k_mbox_put_exit(mbox, timeout, ret)
#define sys_port_trace_k_mbox_async_put_enter(mbox, sem)
#define sys_port_trace_k_mbox_async_put_exit(mbox, sem)
#define sys_port_trace_k_mbox_get_enter(mbox, timeout)
#define sys_port_trace_k_mbox_get_blocking(mbox, timeout)
#define sys_port_trace_k_mbox_get_exit(mbox, timeout, ret)
#define sys_port_trace_k_mbox_data_get(rx_msg)

#define sys_port_trace_k_pipe_init(pipe)
#define sys_port_trace_k_pipe_cleanup_enter(pipe)
#define sys_port_trace_k_pipe_cleanup_exit(pipe, ret)
#define sys_port_trace_k_pipe_alloc_init_enter(pipe)
#define sys_port_trace_k_pipe_alloc_init_exit(pipe, ret)
#define sys_port_trace_k_pipe_flush_enter(pipe)
#define sys_port_trace_k_pipe_flush_exit(pipe)
#define sys_port_trace_k_pipe_buffer_flush_enter(pipe)
#define sys_port_trace_k_pipe_buffer_flush_exit(pipe)
#define sys_port_trace_k_pipe_put_enter(pipe, timeout)
#define sys_port_trace_k_pipe_put_blocking(pipe, timeout)
#define sys_port_trace_k_pipe_put_exit(pipe, timeout, ret)
#define sys_port_trace_k_pipe_get_enter(pipe, timeout)
#define sys_port_trace_k_pipe_get_blocking(pipe, timeout)
#define sys_port_trace_k_pipe_get_exit(pipe, timeout, ret)

#define sys_port_trace_k_heap_init(heap)
#define sys_port_trace_k_heap_aligned_alloc_enter(heap, timeout)
#define sys_port_trace_k_heap_aligned_alloc_blocking(heap, timeout)
#define sys_port_trace_k_heap_aligned_alloc_exit(heap, timeout, ret)
#define sys_port_trace_k_heap_alloc_enter(heap, timeout)
#define sys_port_trace_k_heap_alloc_exit(heap, timeout, ret)
#define sys_port_trace_k_heap_free(heap)
#define sys_port_trace_k_heap_sys_k_aligned_alloc_enter(heap)
#define sys_port_trace_k_heap_sys_k_aligned_alloc_exit(heap, ret)
#define sys_port_trace_k_heap_sys_k_malloc_enter(heap)
#define sys_port_trace_k_heap_sys_k_malloc_exit(heap, ret)
#define sys_port_trace_k_heap_sys_k_free_enter(heap, heap_ref)
#define sys_port_trace_k_heap_sys_k_free_exit(heap, heap_ref)
#define sys_port_trace_k_heap_sys_k_calloc_enter(heap)
#define sys_port_trace_k_heap_sys_k_calloc_exit(heap, ret)

#define sys_port_trace_k_mem_slab_init(slab, rc)
#define sys_port_trace_k_mem_slab_alloc_enter(slab, timeout)
#define sys_port_trace_k_mem_slab_alloc_blocking(slab, timeout)
#define sys_port_trace_k_mem_slab_alloc_exit(slab, timeout, ret)
#define sys_port_trace_k_mem_slab_free_enter(slab)
#define sys_port_trace_k_mem_slab_free_exit(slab)

#define sys_port_trace_k_event_init(event)
#define sys_port_trace_k_event_post_enter(event, events, events_mask)
#define sys_port_trace_k_event_post_exit(event, events, events_mask)
#define sys_port_trace_k_event_wait_enter(event, events, options, timeout)
#define sys_port_trace_k_event_wait_blocking(event, events, options, timeout)
#define sys_port_trace_k_event_wait_exit(event, events, ret)

#define sys_port_trace_k_thread_abort_exit(thread)
#define sys_port_trace_k_thread_abort_enter(thread)
#define sys_port_trace_k_thread_resume_exit(thread)


#define sys_port_trace_pm_system_suspend_enter(ticks)
#define sys_port_trace_pm_system_suspend_exit(ticks, state)

#define sys_port_trace_pm_device_runtime_get_enter(dev)
#define sys_port_trace_pm_device_runtime_get_exit(dev, ret)
#define sys_port_trace_pm_device_runtime_put_enter(dev)
#define sys_port_trace_pm_device_runtime_put_exit(dev, ret)
#define sys_port_trace_pm_device_runtime_put_async_enter(dev, delay)
#define sys_port_trace_pm_device_runtime_put_async_exit(dev, delay, ret)
#define sys_port_trace_pm_device_runtime_enable_enter(dev)
#define sys_port_trace_pm_device_runtime_enable_exit(dev, ret)
#define sys_port_trace_pm_device_runtime_disable_enter(dev)
#define sys_port_trace_pm_device_runtime_disable_exit(dev, ret)

void sys_trace_idle(void);
void sys_trace_isr_enter(void);
void sys_trace_isr_exit(void);

void sys_trace_k_thread_abort_exit(struct k_thread *thread);
void sys_trace_k_thread_abort_enter(struct k_thread *thread);
void sys_trace_k_thread_resume_exit(struct k_thread *thread);
void sys_trace_k_thread_sched_abort(struct k_thread *thread);
void sys_trace_k_thread_sched_ready(struct k_thread *thread);

void sys_trace_k_thread_sched_resume(struct k_thread *thread);
void sys_trace_k_thread_sched_suspend(struct k_thread *thread);

void sys_trace_k_thread_foreach_enter(k_thread_user_cb_t user_cb,
				      void *user_data);
void sys_trace_k_thread_foreach_exit(k_thread_user_cb_t user_cb,
				     void *user_data);
void sys_trace_k_thread_foreach_unlocked_enter(k_thread_user_cb_t user_cb,
					       void *user_data);
void sys_trace_k_thread_foreach_unlocked_exit(k_thread_user_cb_t user_cb,
					      void *user_data);
void sys_trace_k_thread_create(struct k_thread *new_thread, size_t stack_size,
			       int prio);
void sys_trace_k_thread_user_mode_enter(k_thread_entry_t entry, void *p1,
					void *p2, void *p3);
void sys_trace_k_thread_heap_assign(struct k_thread *thread,
				    struct k_heap *heap);
void sys_trace_k_thread_join_blocking(struct k_thread *thread,
				      k_timeout_t timeout);
void sys_trace_k_thread_join_exit(struct k_thread *thread, k_timeout_t timeout,
				  int ret);
void sys_trace_k_thread_sleep_enter(k_timeout_t timeout);
void sys_trace_k_thread_sleep_exit(k_timeout_t timeout, int ret);
void sys_trace_k_thread_msleep_enter(int32_t ms);
void sys_trace_k_thread_msleep_exit(int32_t ms, int ret);
void sys_trace_k_thread_usleep_enter(int32_t us);
void sys_trace_k_thread_usleep_exit(int32_t us, int ret);
void sys_trace_k_thread_busy_wait_enter(uint32_t usec_to_wait);
void sys_trace_k_thread_busy_wait_exit(uint32_t usec_to_wait);
void sys_trace_k_thread_yield(void);
void sys_trace_k_thread_wakeup(struct k_thread *thread);
void sys_trace_k_thread_abort(struct k_thread *thread);
void sys_trace_k_thread_start(struct k_thread *thread);
void sys_trace_k_thread_priority_set(struct k_thread *thread);
void sys_trace_k_thread_suspend(struct k_thread *thread);
void sys_trace_k_thread_resume(struct k_thread *thread);
void sys_trace_k_thread_sched_lock(void);
void sys_trace_k_thread_sched_unlock(void);
void sys_trace_k_thread_name_set(struct k_thread *thread, int ret);
void sys_trace_k_thread_switched_out(void);
void sys_trace_k_thread_switched_in(void);
void sys_trace_k_thread_ready(struct k_thread *thread);
void sys_trace_k_thread_pend(struct k_thread *thread);
void sys_trace_k_thread_info(struct k_thread *thread);

/* Semaphore */

void sys_trace_k_sem_init(struct k_sem *sem, int ret);
void sys_trace_k_sem_give_enter(struct k_sem *sem);

void sys_trace_k_sem_give_exit(struct k_sem *sem);

void sys_trace_k_sem_take_enter(struct k_sem *sem, k_timeout_t timeout);
void sys_trace_k_sem_take_blocking(struct k_sem *sem, k_timeout_t timeout);
void sys_trace_k_sem_take_exit(struct k_sem *sem, k_timeout_t timeout, int ret);
void sys_trace_k_sem_reset(struct k_sem *sem);

/* Mutex */
void sys_trace_k_mutex_init(struct k_mutex *mutex, int ret);
void sys_trace_k_mutex_lock_enter(struct k_mutex *mutex, k_timeout_t timeout);
void sys_trace_k_mutex_lock_blocking(struct k_mutex *mutex,
				     k_timeout_t timeout);
void sys_trace_k_mutex_lock_exit(struct k_mutex *mutex, k_timeout_t timeout,
				 int ret);
void sys_trace_k_mutex_unlock_enter(struct k_mutex *mutex);
void sys_trace_k_mutex_unlock_exit(struct k_mutex *mutex, int ret);

/* Timer */
void sys_trace_k_timer_init(struct k_timer *timer);

void sys_trace_k_timer_start(struct k_timer *timer, k_timeout_t duration,
			     k_timeout_t period);
void sys_trace_k_timer_stop(struct k_timer *timer);
void sys_trace_k_timer_status_sync_blocking(struct k_timer *timer, k_timeout_t timeout);
void sys_trace_k_timer_status_sync_enter(struct k_timer *timer);
void sys_trace_k_timer_status_sync_exit(struct k_timer *timer, uint32_t result);

void sys_trace_k_event_init(struct k_event *event);

#ifdef __cplusplus
}
#endif

#endif /* _TRACE_CTF_H */
