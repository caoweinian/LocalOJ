## 该项目下各子项目功能及数据流

0. 预先说明：
   1. 以下讨论中，设根目录为项目目录，即最外层的LocalOJ目录。
   2. 以下命令均在Linux环境下进行。
1. /manager下是一个C++17项目，make(build)后在/miniOJ下生成二进制文件manage。该二进制文件可以通过接受不同的命令行参数来管理目录/miniOJ下的构建状态：
   - "./manage clear"命令将/miniOJ目录下的状态初始化（删除多余文件），仅保留空文件/miniOJ/db.sqlite3。
   - "./manage init"可在"git clone"获得纯净项目后执行，也可在执行"./manage clear"完毕后执行。该命令将生成必要的辅助二进制文件，并按照一定的顺序执行这些文件，最终保证：
      1. /miniOJ/db.sqlite3成功初始化；
      2. /miniOJ/problem_cases下生成所有问题样例的输入样例和输出样例。
   - "./manage init -p"等同于"./manage clear;./manage init;./manage clear"。
   - "./manage run"（等同于"./manage run -local"）在"./manage init"（或"./manage init -p"）后执行。该命令将读取/miniOJ/problemcases/下的样例和/miniOJ/submit_queue下的所有提交程序并运行核心程序进行判题，在标准输出流中输出运行结果。
   - "./manage run --cfg=x"运行单个测试样例。x或者是一个绝对路径，或者是以/miniOJ为根的相对路径指向一个json文件，后者表明运行限制、源文件语言、源文件路径、输入样例路径、输出文件路径。程序根据这些参数，寻找与该json文件同目录下的所有必要文件，运行测试样例并返回结果。
   - 