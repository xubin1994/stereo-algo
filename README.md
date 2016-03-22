Contains following algorithms:

- FiveRegionStereo - Heiko Hirschmuller, Peter R. Innocent, and Jon Garibaldi. "Real-Time Correlation-Based Stereo Vision with Reduced Border Errors."
- DisparityPropagationStereo - Sun, et al. "Real-time local stereo via edge-aware propagation"

- SADBoxMedian - SAD matching, box aggregating, WTA, median filter postprocessing

Works only for grayscale images. Some adaptation is made in these algorithms and there also might be some bugs.

Following algorithms are not fully implemented for different reasons (read header files of algorithms)

- IDRStereo - edrzej Kowalczuk, et al. "Real-time Stereo Matching on CUDA using an Iterative Refinement Method for Adaptive Support-Weight Correspondences"
- FeatureLinkStereo - Chang-Il Kim, Soon-Yong Park "Fast Stereo Matching of Feature Links"
