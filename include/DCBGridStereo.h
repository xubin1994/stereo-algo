#ifndef DCBGRID_STEREO_H_
#define DCBGRID_STEREO_H_

#include <opencv2/core/core.hpp>

// This is an implementation of "Real-time Spatiotemporal Stereo Matching
// Using the Dual-Cross-Bilateral Grid" - Christian Richardt, et al.
// This is a single threaded implementation of the DCB grid with some slight changes. There is
// no 2S tiling mentioned in the paper, the interpolation is pure quadrilinear interpolation.
// Works only on grayscale images. Might have some bugs that I am not aware of. The implementation
// is not the best or nicest, could be improved and optimized.
class DCBGridStereo {
private:
  // Subsampling
  static constexpr float SIGMA_S = 10;
  static constexpr float SIGMA_R = 10;

  // TAD threshold
  static constexpr float THRESHOLD = 15;

  // Gaussian kernel
  static const int SIZE = 5;
  static constexpr float SIGMA = 1.0;

  // Parameters
  int max_disparity;
  float sigma_s;
  float sigma_r;
  float threshold;

  // aux stuff
  float *cost_volume;
  cv::Mat left;
  cv::Mat right;

  // dcb grid stuff
  float *dcb_grid;
  float *dcb_counts;
  int xdim, ydim, ldim, rdim;
  int dref, xref, yref, lref;

public:
  void tad_matching_cost();
  void create_dcb_grid();
  void process_dcb_grid();
  void slice_dcb_grid();

  DCBGridStereo(int max_disparity, float sigma_s=SIGMA_S, float sigma_r=SIGMA_S, float threshold=THRESHOLD);
  cv::Mat compute_disparity(const cv::Mat &left, const cv::Mat &right);
};

#endif
