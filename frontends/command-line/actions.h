/* actions.h
 *
 * Copyright (C) 2002 Lutz M�ller <lutz@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __ACTIONS_H__
#define __ACTIONS_H__

/* Image actions */
typedef int FileAction    (const char *folder, const char *filename);
int print_file_action     (const char *folder, const char *filename);
int print_exif_action     (const char *folder, const char *filename);
int save_file_action      (const char *folder, const char *filename);
int save_thumbnail_action (const char *folder, const char *filename);
int save_raw_action       (const char *folder, const char *filename);
int save_audio_action     (const char *folder, const char *filename);
int save_exif_action      (const char *folder, const char *filename);
int delete_file_action    (const char *folder, const char *filename);

/* Folder actions */
typedef int FolderAction  (const char *folder);
int delete_all_action     (const char *folder);
int list_files_action     (const char *folder);
int list_folders_action   (const char *folder);

#endif /* __ACTIONS_H__ */
