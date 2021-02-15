#pragma once
#include "camera.h"
#include "common_include.h"
#include "frame.h"

namespace simple_vo
{
	class Dataset 
	{
	public:
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
		typedef std::shared_ptr<Dataset> Ptr;
		Dataset(const std::string& dataset_path);
		bool Init();
		Frame::Ptr NextFrame();

		Camera::Ptr GetCamera(int camera_id) const 
		{
			return cameras_.at(camera_id);
		}

	private:
		std::string dataset_path_;
		int current_image_index_ = 0;

		std::vector<Camera::Ptr> cameras_;
	};
}
