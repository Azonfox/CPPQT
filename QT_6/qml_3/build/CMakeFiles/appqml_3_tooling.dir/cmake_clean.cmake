file(REMOVE_RECURSE
  "qml_3/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/appqml_3_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
