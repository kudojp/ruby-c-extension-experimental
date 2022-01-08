#include "ruby.h"
#include "extconf.h"

VALUE rb_return_nil(){
  return Qnil;
}

void Init_foobar() // This has to be the same the one declared in extconf.rb
{
  VALUE mod = rb_define_module("RubyGuides");
  rb_define_method(mod, "return_nil", rb_return_nil, 0);
}
