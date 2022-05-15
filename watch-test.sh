mkdir build 2> /dev/null
(cd build && cmake .. -G Ninja && ninja && ./tests/all_tests)
  echo "Done"

inotifywait -e close_write,moved_to,create -m tests lib tests |
while read -r directory events filename; do
  (cd build && cmake .. -G Ninja && ninja && ./tests/all_tests)
  echo "Done"
done