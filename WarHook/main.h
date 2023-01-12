#pragma once
#include "includes.h"
#include "math.h"
#include "font.h"
#include "classes.h"
#include "sigs.h"
#include "sigScanner.h"


bool offscreen = false;
bool agree = false;
bool open = true;
bool tab_esp = false;
bool tab_misc = false;
bool tab_debug = false;
bool def_tab = true;
bool def_choice = false;

bool esp_status = false;
bool show_reload = false;
bool show_bots = false;
bool show_planes = false;
bool show_offscreen = false;

bool zoom_mod = false;
bool change_hud = false;
bool force_crosshair = false;
bool force_outline = false;
bool force_distance = false;
bool force_bombsight = false;
bool force_air_to_air = false;

float off_arrow_size = 2.f;
float off_radius = 100.f;
float off_color[]{ 0.f,0.f,0.f };

float zoom_mult = 3.f;
float alt_mult = 12.f;
float shadow_mult = 20.f;

constexpr auto DEFAULT_ZOOM_MULT = 5.f;
constexpr auto DEFAULT_ALT_MULT = 15.f;
constexpr auto DEFAULT_SHADOW_MULT = 20.f;