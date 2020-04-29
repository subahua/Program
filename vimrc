"===========================
"基本设置
"===========================
set nu  "显示行号
set ruler "显示标尺
syntax on "语法高亮
set shortmess =atI
set nocompatible "去除与vi的一致性，避免旧版本的BUG
set laststatus=1 "1启动显示状态行，2总是显示状态行
set foldenable "允许折叠
set foldmethod=manual "手动折叠
filetype plugin indent on "打开文件类型检测
filetype plugin on "允许插件
filetype on "检测文件类型
filetyp indent on "为特定文件载入相关缩进
set tabstop=2 "TAB宽度
set history=1000 "保存的历史记录条数

"===========================
"自动缩进设置
"===========================
set tabstop=4    " 设定 tab 长度为 4
set autoindent     ""自动缩进
set cindent        ""以C语言的方式缩进
set shiftwidth=4   ""设置自动缩进的空格数量
set softtabstop=4  ""tab键的实际占有空格数，统一缩进

"==========================
"Plugin插件设置
"===========================
call plug#begin('~/.vim/Plugin')
"HTML插件
Plug 'mattn/emmet-vim'
"自动补全插件
"Plug 'Valloric/YouCompleteMe'
"Markdown
Plug 'plasticboy/vim-markdown'
"目录树  
Plug 'scrooloose/nerdtree'
"Python 自动补全
"Plug 'davidhalter/jedi-vim'
"Plug 'artur-shaik/vim-javacomplete2'

"代码格式化
"Plug 'Chiel92/vim-autoformat'
"call plug#end()
"autocmd FileType java setlocal omnifunc=javacomplete#Complete

"YouCompleteMe插件配置
".ycm_global_ycm_extra_conf文件路径
"let g:ycm_global_ycm_extra_conf = '$HOME/.vim/Plugin/YouCompleteMe/.ycm_extra_conf.py'
"let g:ycm_show_diagnostics_ui = 1    " 开启实时错误或者warning的检测
"let g:ycm_add_preview_to_completeopt = 0    " 关闭补全预览
" 允许 vim 加载 .ycm_extra_conf.py 文件，不再提示
" let g:ycm_confirm_extra_conf = 0
" 补全内容不以分割子窗口形式出现，只显示补全列表
" set completeopt-=preview
" 补全功能在注释中同样有效
" let g:ycm_complete_in_comments=1
" 开启 YCM 标签补全引擎
" let g:ycm_collect_identifiers_from_tags_files=1
" YCM 集成 OmniCppComplete 补全引擎，设置其快捷键
" inoremap <leader>; <C-x><C-o>
" 从第一个键入字符就开始罗列匹配项
" let g:ycm_min_num_of_chars_for_completion=1
" 禁止缓存匹配项，每次都重新生成匹配项
" let g:ycm_cache_omnifunc=0
" 语法关键字补全
" let g:ycm_seed_identifiers_with_syntax=1
"
" 错误标记
" let g:ycm_error_symbol = '✗'  "set error or warning signs
"
" warning标记
"
" let g:ycm_warning_symbol = '⚠'
"
" highlight YcmErrorSign       标记颜色
" highlight YcmWarningSign ctermbg=none
" highlight YcmErrorSection      代码中出错字段颜色
" highlight YcmWarningSection ctermbg=none
" highlight YcmErrorLine        出错行颜色
" highlight YcmWarningLine



" required" 常用命令
" :PluginList - 查看已经安装的插件
" :PluginInstall - 安装插件
" :PluginUpdate - 更新插件
" :PluginSearch - 搜索插件，例如 :PluginSearch xml就能搜到xml相关的插件
" :PluginClean - 删除插件，把安装插件对应行删除，然后执行这个命令即可
" h: vundle - 获取帮助







"===========================
"头部信息自动插入设置
"=========================== 
"新建.c文件,自动插入文件头
autocmd BufNewFile *.[sh],*.c,*.py,*.java,*.sh exec ":call SetTitle()"
" 定义函数SetTitle
func SetTitle()
	"如果文件类型为.c文件
	if &filetype == 'c'
		call setline(1,"/*************************************")
		call setline(2,"* File-name    :".expand("%***"))
		call setline(3,"* Author       :XOXO             ")
		call setline(4,"* Email        :2546993153@qq.com")
		call setline(5,"* Create       :".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(6,"* Last Modified:".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(7,"**************************************/")
		call setline(8,"#include<stdio.h>")
		call setline(9,"int main(int argc,char * argv[]){")
	endif
	"如果为Java文件
	if &filetype == 'java'
		call setline(1,"/*************************************")
		call setline(2,"* File-name    :".expand("%***"))
		call setline(3,"* Author       :XOXO")
		call setline(4,"* Email        :2546993153@qq.com")
		call setline(5,"* Create       :".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(6,"* Last Modified:".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(7,"*************************************/")
	endif
	"如果为sh文件
	if &filetype == 'sh'
		call setline(1,"#--------------------------------------")
		call setline(2,"#- File-name    :".expand("%***"))
		call setline(3,"#- Author       :XOXO")
		call setline(4,"#- Create       :".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(5,"#- Last Modified:".strftime("%Y-%m-%d %H:%M:%S"))
		call setline(6,"#--------------------------------------")
	"如果为Python文件
	endif
	if &filetype == 'python'
		call setline(1, "\#!/usr/bin/env python")
		call setline(2, "\# _*_ encoding:UTF-8 _*_")
		call setline(3, "\#")
		call setline(4, "\#       @author       : XOXO")
		call setline(5, "\#       @file         : ".expand("%:t"))
		call setline(6, "\#       @date         : ".strftime("%Y/%m/%d %H:%M"))
		call setline(7, "if __name__ == '__main__':") 
	endif
  autocmd BufNewFile * normal G
endfunc 



"===========================
"键盘区
"===========================
" F5 编译并运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w!"
	if &filetype == "c"
		exec "!gcc % -o %<"
		exec "!time ./%<"
		exec "! ./%<"
	elseif &filetype == "py"
		exec "!python %<"
	elseif &filetype == 'java' 
		exec "!javac %" 
		exec "!java %<"
	elseif &filetype == 'sh'
		:!./%
	endif
endfunc




nmap <leader>w :w!<cr>
nmap <leader>f :find<cr>
 
" 映射全选+复制 ctrl+a
 map <C-A> ggVGY
 map! <C-A> <Esc>ggVGY
 map <F12> gg=G
" 选中状态下 Ctrl+c 复制
 vmap <C-c> "+y

"F1目录树
map <F1> :NERDTreeMirror<CR>
map <F1> :NERDTreeToggle<CR>


"===========================
"vim-autoformat插件：
"===========================
"F3自动格式化代码
"noremap <F3> :Autoformat<CR>
"let g:autoformat_verbosemode=1

"保存时自动格式化代码，针对所有支持的文件
"au BufWrite * :Autoformat
""保存时自动格式化PHP代码
"au BufWrite *.php :Autoformat




" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
"set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
