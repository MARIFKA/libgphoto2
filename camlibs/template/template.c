#include <string.h>
#include <gphoto2.h>
#include <gpio.h>

int camera_id (CameraText *id) {

	strcpy(id->text, "REPLACE WITH UNIQUE LIBRARY ID");

	return (GP_OK);
}

int camera_abilities (CameraAbilitiesList *list) {

	CameraAbilities *a;

	a = gp_abilities_new();

	strcpy(a->model, "CAMERA MODEL");
	a->port     = GP_PORT_SERIAL | GP_PORT_USB;
	a->speed[0] = 0;
	a->capture  = GP_CAPTURE_PREVIEW | GP_CAPTURE_VIDEO | GP_CAPTURE_IMAGE;
	a->config   = 1;
	a->file_operations = GP_FILE_OPERATION_DELETE | GP_FILE_OPERATION_PREVIEW;
	a->folder_operations = GP_FOLDER_OPERATION_NONE;

	gp_abilities_list_append(list, a);

	return (GP_OK);
}

int camera_init (Camera *camera) {

	/* First, set up all the function pointers */
	camera->functions->id 			= camera_id;
	camera->functions->abilities 		= camera_abilities;
	camera->functions->init 		= camera_init;
	camera->functions->exit 		= camera_exit;
	camera->functions->folder_list  	= camera_folder_list;
	camera->functions->file_list		= camera_file_list;
	camera->functions->file_get 		= camera_file_get;
	camera->functions->file_get_preview 	=  camera_file_get_preview;
	camera->functions->file_delete 		= camera_file_delete;
	camera->functions->config_get   	= camera_config_get;
	camera->functions->config_set   	= camera_config_set;
	camera->functions->folder_config_get 	= camera_folder_config_get;
	camera->functions->folder_config_set 	= camera_folder_config_set;
	camera->functions->file_config_get 	= camera_file_config_get;
	camera->functions->file_config_set 	= camera_file_config_set;
	camera->functions->capture 		= camera_capture;
	camera->functions->summary		= camera_summary;
	camera->functions->manual 		= camera_manual;
	camera->functions->about 		= camera_about;
	camera->functions->result_as_string 	= camera_result_as_string;

	return (GP_OK);
}

int camera_exit (Camera *camera) {

	return (GP_OK);
}

int camera_folder_list	(Camera *camera, CameraList *list, char *folder) {

	return (GP_OK);
}

int camera_file_list (Camera *camera, CameraList *list, char *folder) {

	return (GP_OK);
}

int camera_file_get (Camera *camera, CameraFile *file, 
		     char *folder, char *filename) { 

	return (GP_OK);
}

int camera_file_get_preview (Camera *camera, CameraFile *file,
			     char *folder, char *filename) {

	return (GP_OK);
}

int camera_file_put (Camera *camera, CameraFile *file, char *folder) {

	return (GP_OK);
}

int camera_file_delete (Camera *camera, char *folder, char *filename) {

	return (GP_OK);
}

int camera_config_get (Camera *camera, CameraWidget **window) {

	*window = gp_widget_new (GP_WIDGET_WINDOW, "Camera Configuration");

	// Append your sections and widgets here.

	return (GP_OK);
}

int camera_config_set (Camera *camera, CameraWidget *window) {

	// Check, if the widget's value have changed.

	return (GP_OK);
}

int camera_folder_config_get (Camera *camera, CameraWidget **window, char *path) {

	// For example, create a window with a button named "Delete all". 

	return (GP_OK);
}

int camera_folder_config_set (Camera *camera, CameraWidget *window, char *path) {

	return (GP_OK);
}

int camera_file_config_get (Camera *camera, CameraWidget **window, char *path, char *file) {

	return (GP_OK);
}

int camera_file_config_set (Camera *camera, CameraWidget *window, char *path, char *file) {

	return (GP_OK);
}

int camera_capture (Camera *camera, CameraFile *file, CameraCaptureInfo *info) {

	// Capture image/preview/video and return it in 'file'. Don't store it
	// anywhere on your camera! If your camera does store the image, 
	// delete it manually here.

	return (GP_OK);
}

int camera_summary (Camera *camera, CameraText *summary) {

	return (GP_OK);
}

int camera_manual (Camera *camera, CameraText *manual) {

	return (GP_OK);
}

int camera_about (Camera *camera, CameraText *about) {

	strcpy(about->text, 
"Library Name
YOUR NAME <email@somewhere.com>
Quick description of the library.
No more than 5 lines if possible.");

	return (GP_OK);
}

char* camera_result_as_string (Camera *camera, int result) {
	
	if (result >= 0) return ("This is not an error...");
	if (-result < 100) return gp_result_as_string (result);
	return ("This is a template specific error.");
}
