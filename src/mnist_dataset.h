#ifndef __mnist_dataset_h__
#define __mnist_dataset_h__

#include "dataset.h"

#include <stdint.h>

class MnistDataset : public Dataset {
public:
  MnistDataset(const char *images_filename, const char *labels_filename);
  ~MnistDataset();
  virtual bool get_value(int i);
  virtual void get_sample(gsl_rng *r, gsl_vector *sample, int example_id);
  virtual void get_state(gsl_vector *sample, int example_id);
  virtual int get_label(int example_id);
  
private:
  int32_t m_num_images;
  int32_t m_num_rows;
  int32_t m_num_cols;
  uint8_t **m_image_data;
  uint8_t *m_labels;

  void load_images(const char *filename);
  void load_labels(const char *filename);
};

#endif
