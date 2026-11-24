{
  description = "Competitive Programming Shell";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      systems = [ "x86_64-linux" "aarch64-linux" ];
    in
    {
      devShells = nixpkgs.lib.genAttrs systems (system:
        let
          pkgs = import nixpkgs { inherit system; };
        in
        {
          default = pkgs.mkShell {
            packages = with pkgs; [
              gcc
              jdk
              pypy3
              util-linux
              clang-tools
              ty
              uv
              jdt-language-server
              tree-sitter
              curl
              gnutar
              gzip
            ];

            shellHook = ''
              if [ -n "''${BASH_VERSION:-}" ] && type complete >/dev/null 2>&1; then
                source ${pkgs.bash-completion}/share/bash-completion/bash_completion
                export FZF_CTRL_R_COMMAND= FZF_CTRL_T_COMMAND= FZF_ALT_C_COMMAND=
                if [[ $- == *i* ]]; then
                  bind '"\C-r": reverse-search-history'
                  bind '"\C-t": transpose-chars'
                  bind '"\ec": capitalize-word'
                fi
              fi

              alias nvim='NVIM_APPNAME=cimp nvim'
              alias myg++='g++ -L${pkgs.glibc.static}/lib -x c++ -std=gnu++23 -Wall -O2 -static -pipe -g'
              alias judgeg++='g++ -L${pkgs.glibc.static}/lib -x c++ -std=gnu++23 -Wall -O2 -static -pipe -DONLINE_JUDGE -DDOMJUDGE'
              mygcc() {
                gcc -L${pkgs.glibc.static}/lib -x c -std=gnu23 -Wall -O2 -static -pipe -g "$@" -lm
              }
              judgegcc() {
                gcc -L${pkgs.glibc.static}/lib -x c -std=gnu23 -Wall -O2 -static -pipe -DONLINE_JUDGE -DDOMJUDGE "$@" -lm
              }
              alias myjavac='javac -encoding UTF-8 -sourcepath . -d .'
              alias judgejavac='javac -encoding UTF-8 -sourcepath . -d .'
              alias myjava='taskset -c 3 java -Dfile.encoding=UTF-8 -XX:+UseSerialGC -Xss64m -Xms1920m -Xmx1920m'
              alias judgejava='taskset -c 3 java -Dfile.encoding=UTF-8 -DONLINE_JUDGE -DDOMJUDGE -XX:+UseSerialGC -Xss64m -Xms1920m -Xmx1920m'
              alias mypython3compile='pypy3 -m py_compile'
              alias judgepython3compile='pypy3 -m py_compile'
              alias mypython3='pypy3'
              alias judgepython3='env ONLINE_JUDGE=1 DOMJUDGE=1 pypy3'
              alias mypypy3compile='pypy3 -m py_compile'
              alias judgepypy3compile='pypy3 -m py_compile'
              alias mypypy3='pypy3'
              alias judgepypy3='env ONLINE_JUDGE=1 DOMJUDGE=1 pypy3'
              alias printfile='submit --print'
            '';
          };
        });
    };
}
