#include <gphoto2-core.h>
#include <gphoto2-camera.h>

#include <stdio.h>

#define CHECK(f) {int res = f; if (res < 0) {printf ("ERROR: %s\n", gp_result_as_string (res)); exit (1);}}

int
main (int argc, char *argv [])
{
	CameraText text;
	Camera *camera;
	CameraAbilities abilities;

	/*
	 * You don't have to initialize libgphoto2 anymore. We do that
	 * internally.
	 */

	/*
	 * You'll probably want to access your camera. You will first have
	 * to create a camera (that is, allocating the memory).
	 */
	printf ("Creating camera...\n");
	CHECK (gp_camera_new (&camera));

	/*
	 * Before you initialize the camera, set the model so that
	 * gphoto2 knows which library to use.
	 */
	printf ("Setting model...\n");
	CHECK (gp_camera_abilities_by_name ("Directory Browse", &abilities));
	CHECK (gp_camera_set_abilities (camera, abilities));

	/*
	 * Now, initialize the camera (establish a connection).
	 */
	printf ("Initializing camera...\n");
	CHECK (gp_camera_init (camera));

	/*
	 * At this point, you can do whatever you want. Here, we get
	 * a summary and print it. You could get files, capture images...
	 */
	printf ("Getting summary...\n");
	CHECK (gp_camera_get_summary (camera, &text));
	printf ("%s\n", text.text);

	/*
	 * Don't forget to clean up when you don't need the camera any
	 * more. Please use unref instead of destroy - you'll never know
	 * if some part of the program still needs the camera.
	 */
	printf ("Unrefing camera...\n");
	CHECK (gp_camera_unref (camera));

	/*
	 * And when you don't need gphoto2 any more, exit.
	 */
	printf ("Exiting gphoto2...\n");
	CHECK (gp_exit ());

	return (0);
}
