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

VALUE rb_print_length(VALUE self, VALUE str) { // the receiver of this method is passed as self.
  if (RB_TYPE_P(str, T_STRING) == 1){
    return rb_sprintf("String length: %ld", RSTRING_LEN(str));
  }
  return Qnil;
}

VALUE rb_print_receiver_length(VALUE self) {
  if (RB_TYPE_P(self, T_STRING) == 1){
    return rb_sprintf("String length: %ld", RSTRING_LEN(self));
  }
  return Qnil;
}

void Init_foobar() // This has to be the same the one declared in extconf.rb
{
  VALUE mod = rb_define_module("RubyGuides");
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
  rb_define_method(mod, "create_hash", rb_create_hash, 0);
  rb_define_method(mod, "print_length", rb_print_length, 1); // define onto the RubyGuides module
  rb_define_method(rb_cString, "print_length", rb_print_receiver_length, 0); // define onto the String class
}
