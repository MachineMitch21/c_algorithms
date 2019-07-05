obj_dir="obj"
src_dir="src"
out_dir="build"
prog_name="calgs"

mkdir -p "$obj_dir" "$out_dir"

for c_file in $(find "$src_dir" -type f -name '*.c'); do
  gcc -Wall -Wextra -pedantic -c -o "$obj_dir"/$(basename "$c_file").o "$c_file"
done

gcc -o "$out_dir"/"$prog_name" "$obj_dir"/*.o