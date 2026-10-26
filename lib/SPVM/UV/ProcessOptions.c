// Copyright (c) 2026 Yuki Kimoto
// MIT License

#include "spvm_native.h"
#include "uv.h"
#include "spvm_uv.h"

static const char* FILE_NAME = "UV/ProcessOptions.c";

int32_t SPVM__UV__ProcessOptions__new(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  uv_process_options_t* options = env->new_memory_block(env, stack, sizeof(uv_process_options_t));
  memset(options, 0, sizeof(uv_process_options_t));
  
  SPVM_OBJ* obj_options = env->new_pointer_object_by_name(env, stack, "UV::ProcessOptions", options, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__file(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_file = env->get_field_object_by_name(env, stack, obj_options, "file", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_file;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_file(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_file = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "file", obj_file, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  if (obj_file) {
    options->file = env->get_chars(env, stack, obj_file);
  }
  else {
    options->file = NULL;
  }
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__args(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_args = env->get_field_object_by_name(env, stack, obj_options, "args", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_args;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_args(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_args = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "args", obj_args, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  if (obj_args) {
    int32_t args_length = env->length(env, stack, obj_args);
    char** args = env->new_memory_block(env, stack, sizeof(char*) * (args_length + 1));
    for (int32_t i = 0; i < args_length; i++) {
      SPVM_OBJ* obj_arg = env->get_elem_object(env, stack, obj_args, i);
      if (obj_arg) {
        args[i] = (char*)env->get_chars(env, stack, obj_arg);
      }
      else {
        args[i] = NULL;
      }
    }
    args[args_length] = NULL;
    options->args = args;
  }
  else {
    options->args = NULL;
  }
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__env(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_env = env->get_field_object_by_name(env, stack, obj_options, "env", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_env;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_env(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_env = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "env", obj_env, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  if (obj_env) {
    int32_t env_length = env->length(env, stack, obj_env);
    char** env_strs = env->new_memory_block(env, stack, sizeof(char*) * (env_length + 1));
    for (int32_t i = 0; i < env_length; i++) {
      SPVM_OBJ* obj_env_str = env->get_elem_object(env, stack, obj_env, i);
      if (obj_env_str) {
        env_strs[i] = (char*)env->get_chars(env, stack, obj_env_str);
      }
      else {
        env_strs[i] = NULL;
      }
    }
    env_strs[env_length] = NULL;
    options->env = env_strs;
  }
  else {
    options->env = NULL;
  }
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__cwd(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_cwd = env->get_field_object_by_name(env, stack, obj_options, "cwd", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_cwd;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_cwd(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_cwd = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "cwd", obj_cwd, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  if (obj_cwd) {
    options->cwd = env->get_chars(env, stack, obj_cwd);
  }
  else {
    options->cwd = NULL;
  }
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__flags(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  stack[0].ival = options->flags;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_flags(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  int32_t flags = stack[1].ival;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  options->flags = flags;
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__stdio(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_stdio = env->get_field_object_by_name(env, stack, obj_options, "stdio", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_stdio;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_stdio(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_stdio = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "stdio", obj_stdio, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  if (obj_stdio) {
    int32_t stdio_length = env->length(env, stack, obj_stdio);
    options->stdio_count = stdio_length;
    uv_stdio_container_t* stdio = env->new_memory_block(env, stack, sizeof(uv_stdio_container_t) * stdio_length);
    for (int32_t i = 0; i < stdio_length; i++) {
      SPVM_OBJ* obj_container = env->get_elem_object(env, stack, obj_stdio, i);
      if (obj_container) {
        uv_stdio_container_t* container = env->get_pointer(env, stack, obj_container);
        assert(container);
        stdio[i] = *container;
      }
      else {
        memset(&stdio[i], 0, sizeof(uv_stdio_container_t));
      }
    }
    options->stdio = stdio;
  }
  else {
    options->stdio_count = 0;
    options->stdio = NULL;
  }
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__exit_cb(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  SPVM_OBJ* obj_exit_cb = env->get_field_object_by_name(env, stack, obj_options, "exit_cb", &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_exit_cb;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__set_exit_cb(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  SPVM_OBJ* obj_exit_cb = stack[1].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  assert(options);
  
  env->set_field_object_by_name(env, stack, obj_options, "exit_cb", obj_exit_cb, &error_id, __func__, FILE_NAME, __LINE__);
  if (error_id) return error_id;
  
  stack[0].oval = obj_options;
  
  return 0;
}

int32_t SPVM__UV__ProcessOptions__DESTROY(SPVM_ENV* env, SPVM_VALUE* stack) {
  
  int32_t error_id = 0;
  
  SPVM_OBJ* obj_options = stack[0].oval;
  
  uv_process_options_t* options = env->get_pointer(env, stack, obj_options);
  
  int32_t no_free = env->no_free(env, stack, obj_options);
  if (!no_free) {
    if (options->args) {
      env->free_memory_block(env, stack, options->args);
    }
    if (options->env) {
      env->free_memory_block(env, stack, options->env);
    }
    if (options->stdio) {
      env->free_memory_block(env, stack, options->stdio);
    }
    env->free_memory_block(env, stack, options);
  }
  
  return 0;
}
