#pragma once

#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "fluidsimulation.h"
#include "polygonizer3d.h"
#include "ImplicitField.h"
#include "Array3d.h"
#include "trianglemesh.h"
#include "game/camera/camera3d.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "aabb.h"

class FluidRenderer
{
public:
    FluidRenderer();
    FluidRenderer(FluidSimulation *sim);
    ~FluidRenderer();

    void update(float dt);
    void draw();

    void setScale(double s) { scale = s; }
    void setDrawOffset(double x, double y, double z) { tx = x; ty = y; tz = z; }

    void drawGrid();
    void drawGridBoundingBox();
    void drawSolidCells();
    void drawFluidCells();
    void drawAirCells();
    void drawImplicitFluidPoints();
    void drawMarkerParticles();
    void drawLayerGrid();
    void drawBillboardTextures(GLuint tex, double width, Camera3d *cam);
    void drawSurfaceCells();
    void drawSurfaceTriangles();
private:
    int M_AIR = 0;
    int M_FLUID = 1;
    int M_SOLID = 2;

    void _drawWireframeCube(glm::vec3 p, double size);
    void _drawFluidMaterialType(int mType);
    void _drawImplicitPointData(ImplicitPointData p);

    void _setTransforms();
    void _unsetTransforms();

    FluidSimulation *fluidsim;

    double scale = 1.0;
    double tx = 0.0;
    double ty = 0.0;
    double tz = 0.0;

};
