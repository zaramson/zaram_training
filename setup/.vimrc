
set clipboard=unnamedplus
set number
set hlsearch
"set nowrap

set ts =4                 
set ai  "autoindent
set ruler "Display the number of lines in the lower right corner


set cursorline


colors desert

"map <F4> /sdfdsfsdfsdf<CR> 


set lines=35
"set columns=90


"set guifont=

set guifont=Monospace\ Regular\ 13



"==================================================
" Map Setting
"==================================================
nmap ,s			:w<CR> :source ~/.vimrc<CR> :noh<CR>
nmap ,v			:e	~/.vimrc<CR>
nmap ,b			:e  ~/.bash_aliases<CR>
nmap ,t			:!cd ~/projects;ctags -R<CR><CR>
nmap ,1			:e	~/.vim/pack/plugins/start/vim-snippets/snippets/verilog.snippets<CR>
nmap ,2			:e	~/.vim/pack/plugins/start/vim-snippets/snippets/_.snippets<CR>
nmap ,3			:e	~/.vim/pack/custom/start/vim-verilog/autoload/verilog.vim<CR>
nmap ,4			:e	~/.vim/pack/custom/start/vim-functions/autoload/cstFuncs.vim<CR>
nmap ,q			:q<CR>
nmap ,w			:w<CR>

"	~/.vim/pack/custom/vim-functions/autoload/cstFuncs.vim
nmap f*			:call cstFuncs#FontChange()<CR>
nmap f[			:call cstFuncs#FontSizeMod(-1)<CR>
nmap f]			:call cstFuncs#FontSizeMod(+1)<CR>
nmap s[			:call cstFuncs#LineSpace(-1)<CR>
nmap s]			:call cstFuncs#LineSpace(+1)<CR>
nmap c[			:call cstFuncs#CMDHeight(-1)<CR>
nmap c]			:call cstFuncs#CMDHeight(+1)<CR>

nmap \n			:call cstFuncs#ToggleRelativeNumber()<CR>
nmap \l			:call cstFuncs#ToggleCursorLine()<CR>
nmap \c			:call cstFuncs#ToggleListChars()<CR>
nmap \m			:call cstFuncs#ToggleGUIMenu()<CR>

map ga			:Tabularize /

map ,n			:noh<CR>
"	~/.vim/pack/custom/vim-verilog/autoload/verilog.vim
map ,,i			:call verilog#VInst(0)<CR>
map ,,t			:call verilog#VInst(1)<CR>

map <F2>		:NERDTreeToggle<CR>
map <F3>		:IndentGuidesToggle<CR>
map	<F4>		:SyntasticToggleMode<CR>
map <F5>		:TagbarToggle<CR>
map <F8>		:w <CR> :!ivg	%:r:s?_tb??<CR>
map <F9>		:w <CR> :!iv	%:r:s?_tb??<CR><CR>

map <F11>		: w <CR> : !python3 %<CR><CR>
map <F12>		: w <CR> : !clear; riscv64-unknown-linux-gnu-gcc -march=rv32i -mabi=ilp32 -g -Wall %:t -o %:t:r <CR>
"map <F12>		: w <CR> : !clear; riscv64-unknown-linux-gnu-gcc -march=rv32imac -mabi=ilp32 -g -Wall %:t -o %:t:r <CR>
"map <F12>		: w <CR> : !clear; gcc -g -Wall %:t -o %:t:r && ./%:t:r<CR>
"map <F11>		: VimwikiAll2HTML<CR>
"map <F12>		: %!xxd<CR>
map <C-LEFT>	: tabprev<CR>
map <C-RIGHT>	: tabnext<CR>
map <C-n>		: tabnew<CR>

map <C-S>	<C-U>

imap <C-J> <Plug>snipMateNextOrTrigger



