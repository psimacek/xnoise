/* pl-pls-file-reader.vala
 *
 * Copyright (C) 2010  Jörn Magens
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Francisco Pérez Cuadrado <fsistemas@gmail.com>
 * 	Jörn Magens <shuerhaaken@googlemail.com>
 */

namespace Pl {
	// base class for all playlist filereader implementations
	private class Pls.FileReader : AbstractFileReader {
		private unowned File file;
		
		public override DataCollection read(File _file) throws InternalReaderError {
			DataCollection data_collection = new DataCollection();
			this.file = _file;
			set_base_path();
			if(!file.query_exists(null)) { 
				stderr.printf ("File '%s' doesn't exist.\n", file.get_uri());
				return data_collection;
			}

			try {
				var in_stream = new DataInputStream (file.read(null));
				string line;
				int numberofentries = 0;
				string[] line_buf = {};
				//Read header => [playlist]
				if((line = in_stream.read_line(null, null)) != null) {
					if (!line.has_prefix( "[playlist]" ) ) {
						return data_collection;
					}
					Data d = null;
					while((line = in_stream.read_line (null, null)) != null) {
						
						//Ignore blank line
						if(line._strip().size() == 0) { 
							continue; 
						}
						if(line.down().contains("numberofentries")) {
							var arrayNumberOfEntries = line.split("=");
							
							//Can we rely on existance of numberofentries??
							if(arrayNumberOfEntries.length == 2) {
								numberofentries = arrayNumberOfEntries[1].to_int();
								//print("There are %d entries: \n", numberofentries);
							}
							else {
								//error
							}
							continue;
						}
						else {
							line_buf += line;
						}

					}
					
					for(int i = 1; i <= numberofentries; i++) {
						d = new Data();
						for(int j = 0; j < line_buf.length; j++) {
							if(line_buf[j].has_prefix("File" + i.to_string())) {
								if(line_buf[j].contains("=")) {
									char* begin = line_buf[j].str("=");
									begin++;
									char* end = (char*)line_buf[j] + line_buf[j].size();
									if(begin >= end)
										break;
									TargetType tt;
									File tmp = get_file_for_location(((string)begin)._strip(), ref base_path, out tt);
									d.add_field(Data.Field.URI, tmp.get_uri());
									d.target_type = tt;
									break;
								}
								else {
									break;
								}
							}
							
						}
						for(int j = 0; j < line_buf.length; j++) {
							if(line_buf[j].has_prefix("Title" + i.to_string())) {
								if(line_buf[j].contains("=")) {
									char* begin = line_buf[j].str("=");
									begin++;
									char* end = (char*)line_buf[j] + line_buf[j].size();
									if(begin >= end)
										break;
									line_buf[j] = ((string)begin)._strip();
									d.add_field(Data.Field.TITLE, line_buf[j]);
									break;
								}
								else {
									break;
								}
							}
						}
						if(d.get_uri() != null)
							data_collection.append(d);
					}
				}
			} 
			catch (GLib.Error e) {
				print("Error: %s\n", e.message);
				error ("%s", e.message);
			}
			return data_collection;
		}

		public override async DataCollection read_asyn(File _file) throws InternalReaderError {
			DataCollection data_collection = new DataCollection();
			this.file = _file;
			set_base_path();
			return data_collection;
		}

		protected override void set_base_path() {
			base_path = file.get_parent().get_uri();
		}
	}
}
