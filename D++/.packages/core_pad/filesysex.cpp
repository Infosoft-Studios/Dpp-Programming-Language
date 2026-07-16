#include <frigg/frigg.hpp>
#include <lil/intel.hpp>
#include <lil/context.hpp>
#include <lil/queue.hpp>
#include <windows.h>

// headers
frigg::loadfunction<assets::init>
frigg::loadH(nullptr, true);

// reint casts and auto 
auto function_load = reintepeter_cast<void*> load();
