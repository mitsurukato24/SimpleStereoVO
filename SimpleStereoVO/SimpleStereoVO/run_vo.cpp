#include <gflags/gflags.h>
#include "visual_odometry.h"

DEFINE_string(config_file, "./kitti.yml", "config file path");

int main(int argc, char **argv) 
{
	google::ParseCommandLineFlags(&argc, &argv, true);

	simple_vo::VisualOdometry::Ptr vo(new simple_vo::VisualOdometry(FLAGS_config_file));
	assert(vo->Init() == true);
	vo->Run();

	return 0;
}