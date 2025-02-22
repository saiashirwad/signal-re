(lang dune 3.17)

(using melange 0.1)

(name signals_re)

(generate_opam_files true)

(source
 (github saiashirwad/signals-re))

(authors "Sai Ashirwad <saiashirwad@gmail.com>")

(maintainers "Sai Ashirwad <saiashirwad@gmail.com>")

(license MIT)

(package
 (allow_empty)
 (name signals_re)
 (synopsis "A signals implementation in ReasonML")
 (description "A signals implementation in ReasonML")
 (depends ocaml dune melange reason-react reason-react-ppx)
 (tags
  ("signals" "react" "reasonml")))
