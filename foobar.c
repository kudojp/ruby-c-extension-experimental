#include "ruby.h"
#include "extconf.h"

VALUE rb_return_nil(){
  return Qnil;
}

VALUE rb_create_hash() {
  VALUE hash = rb_hash_new(); // creates a ruby string (=VALUE struct in C ???)

  // set the hash key to value
  rb_hash_aset(hash, rb_str_new2("test"), INT2FIX(1));
  return hash;
}

void Init_foobar() // This has to be the same the one declared in extconf.rb
{
  VALUE mod = rb_define_module("RubyGuides");
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
  rb_define_method(mod, "create_hash", rb_create_hash, 0);
}
