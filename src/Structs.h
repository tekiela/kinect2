#ifndef Kinect2_Structs_h
#define Kinect2_Structs_h

#include "Globals.h"

typedef struct _JSJoint
{
	float depthX;
	float depthY;
	float colorX;
	float colorY;
	float cameraX;
	float cameraY;
	float cameraZ;
	USHORT rawDepth;
	//
	bool hasFloorData;
	float floorDepthX;
	float floorDepthY;
	float floorColorX;
	float floorColorY;
	float floorCameraX;
	float floorCameraY;
	float floorCameraZ;
	//
	int jointType;
} JSJoint;

typedef struct _JSBody
{
	bool tracked;
	bool hasPixels;
	bool trackPixels;
	UINT64 trackingId;
	char leftHandState;
	char rightHandState;
	JSJoint joints[JointType_Count];
	RGBQUAD colorPixels[cColorWidth * cColorHeight];
	char depthPixels[cDepthWidth * cDepthHeight];
	char infraredPixels[cInfraredWidth * cInfraredHeight];
	char longExposureInfraredPixels[cLongExposureInfraredWidth * cLongExposureInfraredHeight];
} JSBody;

typedef struct _JSBodyFrame
{
	JSBody bodies[BODY_COUNT];
	//
	bool hasFloorClipPlane;
	float floorClipPlaneX;
	float floorClipPlaneY;
	float floorClipPlaneZ;
	float floorClipPlaneW;
	//
	float cameraAngle;
	float cosCameraAngle;
	float sinCameraAngle;
} JSBodyFrame;

#endif
