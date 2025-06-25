#ifndef VMF3_FUNCTIONS_H
#define VMF3_FUNCTIONS_H

#include "rtklib.h" // Inclua rtklib.h aqui para tipos como gtime_t e MAXSTRPATH

// Macro para interpolação linear (necessária em alguns headers para funções inline ou macros)
#define LERP(v1, v2, alpha) ((v1) * (1.0 - (alpha)) + (v2) * (alpha))

// Protótipos das funções VMF3 (EXPORTadas)
EXPORT void init_vmf3_cache(const char *dir);
EXPORT int read_vmf3_hxx_file_C(const char *filepath, vmf3_grid_data_t *grid_data_out);
EXPORT int interpolate_vmf3_grid_coeffs_C(const vmf3_grid_data_t *grid, double station_lat_deg, double station_lon_deg,
                                         double *ah_interp_out, double *aw_interp_out, double *zhd_interp_out, double *zwd_interp_out,
                                         double *gn_h_interp_out, double *ge_h_interp_out, double *gn_w_interp_out, double *ge_w_interp_out);
EXPORT void calculate_vmf3_mapping_factors_C(double mjd, double lat_rad, double lon_rad, double h_ell, double zd_rad, double ah, double aw, double *mfh_out, double *mfw_out);
EXPORT int get_vmf3_data_for_time(gtime_t time, vmf3_grid_data_t **grid1_out, vmf3_grid_data_t **grid2_out);

#endif // vmf3_functions_H