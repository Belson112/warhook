#pragma once
#include "includes.h"

static bool offscreen = false;
static bool agree = false;
static bool open = true;
static bool tab_esp = false;
static bool tab_misc = false;
static bool tab_debug = false;
static bool def_tab = true;
static bool def_choice = false;

static bool esp_status = false;
static bool show_reload = false;
static bool show_bots = false;
static bool show_planes = false;
static bool show_offscreen = false;

static bool zoom_mod = false;
static bool change_hud = false;
static bool force_crosshair = false;
static bool force_outline = false;
static bool force_distance = false;
static bool force_bombsight = false;

static float zoom_mult = 3.f;
static float alt_mult = 12.f;
static float shadow_mult = 20.f;
float off_arrow_size = 2.f;
float off_radius = 100.f;
float off_color[] {0.f,0.f,0.f};