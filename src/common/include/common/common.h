#include <recon/PointCloudSampler.h>
#include <recon/AbstractSensor.h>
#include <ofMain.h>

/**
* Calculates an approximate rolling average value from a previous average, a new sample and a sample window size.
*/
float approxRollingAverage(
	float avg, 
	float new_sample, 
	int window);
/**
* Downsamples the source pointcloud to resolution and stores it in target.
*/
void downsample(
	recon::CloudConstPtr src, 
	recon::CloudPtr trgt, 
	float resolution);
void downsample(
	recon::CloudPtr src,
	recon::CloudPtr trgt,
	float resolution);
void downsample(
	recon::NormalCloudPtr src,
	recon::NormalCloudPtr trgt,
	float resolution);

/**
* A simple Depth threshold filter. keepOrganized should be set to true if for example the resrult should be meshed using OrganizedFastMesh.
* Ransac however is much faster when keepOrganized is set to false. That is because organized Pointclouds keep removed Points as placeholders
*/
void removeBackground(
	recon::CloudPtr src, 
	recon::CloudPtr trgt, 
	float min, 
	float max, 
	bool keepOrganized);
void removeBackground(
	recon::CloudConstPtr src, 
	recon::CloudPtr trgt, 
	float min, 
	float max, 
	bool keepOrganized);

/**
* Divides the input cloud into an inlier and outlier cloud by inlier point indices.
*/
void extractInOutliers(
	recon::CloudPtr src, 
	pcl::PointIndices::Ptr inliers, 
	recon::CloudPtr in_cloud,
	recon::CloudPtr out_cloud);

/**
* Creates triangles for pointcloud using organized fast mesh. Input mesh has to be organized.
*/
void organizedFastMesh(
	recon::CloudPtr src, 
	recon::TrianglesPtr &triangles, 
	int edgeLength, 
	float angleTolerance, 
	float distanceTolerance);
void organizedFastMesh(
	recon::CloudConstPtr src, 
	recon::TrianglesPtr &triangles, 
	int edgeLength, 
	float angleTolerance, 
	float distanceTolerance);

/**
* Moving-Least Squares Smoothing of Point cloud with normals
*/
void movingLeastSquaresSmoothing(
	recon::NormalCloudPtr src,
	recon::NormalCloudPtr trgt,
	float smoothRadius
	);

/**
* Calculates point normals
*/
void calculatePointNormals(recon::CloudPtr src, recon::NormalCloudPtr trgt, int normalKNeighbours);

/**
* Creates triangles for pointcloud with normals using greedy projection triangulation.
*/
void greedyProjectionMesh(
	recon::NormalCloudPtr src, 
	recon::TrianglesPtr& triangles, 
	float maxEdgeLength,
	float mu, 
	int maxNearestNeighbours,
	float maxSurfaceDegree, 
	float minTriDegree, 
	float maxTriDegree);

/**
* Draws the camera frustum in world space using given sensor intrisics and extrinsics.
*/
void drawCameraFrustum(recon::AbstractSensor::Ptr sensor);

/**
* Calculates the texture coordinate of a 3D point by projecting it through the sensors intrinsics onto an image plane of texture size.
*/
ofVec2f calculateTextureCoordinate(
	ofVec3f &point, 
	float texwidth, 
	float texheight,
	recon::AbstractSensor::Ptr sensor,
	bool inCameraSpace);

/**
* Creates an ofMesh with texture coodinates from a point cloud, the triangulates triangles and the texture of the sensor.
*/
void createOfMeshWithTexCoords(
	pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr src, 
	boost::shared_ptr<std::vector<pcl::Vertices>> triangles, 
	ofTexture & texture, 
	recon::AbstractSensor::Ptr sensor, 
	ofMesh &targetMesh);

void createOfMeshWithCombinedTexCoords(
	pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr src, 
	boost::shared_ptr<std::vector<pcl::Vertices>> triangles, 
	ofTexture & texture, 
	ofRectangle &texturelayout,
	recon::AbstractSensor::Ptr sensor, 
	ofMesh &targetMesh);
void createOfMeshWithCombinedTexCoords(
	pcl::PointCloud<pcl::PointXYZRGBNormal>::ConstPtr src,
	boost::shared_ptr<std::vector<pcl::Vertices>> triangles,
	std::vector<ofVec2f> &texcoords,
	ofMesh &targetMesh);


void createOfMeshFromPclTextureMesh(
	pcl::TextureMeshPtr mesh, 
	std::vector<ofRectangle>& texturelayout, 
	std::map<int, recon::AbstractSensor::Ptr> sensors, 
	std::map<int, std::shared_ptr<ofImage>> &texture,
	ofMesh &targetMesh,
	bool camIndexColor);


ofColor getSensorColor(int sensorId);
