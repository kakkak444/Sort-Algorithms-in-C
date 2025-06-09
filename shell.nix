{ pkgs ? import <nixpkgs> {} }:

let
	workspace = ./.;
in
	pkgs.mkShell {
		buildInputs = [
			pkgs.gcc
			pkgs.git
			pkgs.gdb
		];

		shellHook = ''
			alias gcc="gcc -Wall -Wextra -I\"${workspace}/\""
		'';
	}
