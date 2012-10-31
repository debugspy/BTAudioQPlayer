BTAudioQPlayer
=====
部分核心代码来自[DigitalDJ/AudioStreamer](git://github.com/DigitalDJ/AudioStreamer.git)

AudioStreamer存在的问题 
=====
1. 代码结构完全过程化
2. 播放状态变量太多，状态之间不容易区分，不易理解和调试。
3. 音频数据的下载只能随着播放的进度进行，不能异步下载，提前缓冲数据
4. 对网络的支持较弱，对拖拽的操作，完全重新发送请示
5. 有小概率混音的BUG
6. 错误处理比较麻烦
7. 等待网络数据返回时，不能一有数据就播放，需要多缓冲一会儿再播放
8. 不支持播放列表
9. 不能预先加载下一个音频的数据
10. 自动识别网络和本地数据

我们的播放器除上面的问题外还有：
=====
1. 周期性驱动的效率是否足够高效？
2. 可以提前缓冲数据，对拖拽的操作，只支持拖拽到已经缓冲的位置
3. 播放控制，单曲循环，列表循环，不循环等
4. 当前播放信息的对外通知和同步

关于状态
=====
使用状态变量的时候应该注意，避免各状态所表述的内容有交叉，比如AS_STOPPING和AS_PLAYING，AS_STOPPING也是种播放ing的状态。AS_STARTING_FILE_THREAD其实也AS_WAITING_FOR_DATA这样的状态设置将导致后续难以维护  
单纯从播放器的角度来看待状态，只需要有以下几种，（或者从用户可见（UI）的状态来看）,其他的内部状态不需要让用户知道

* stop: 初始和最终，都应该是这个状态。也有可能是因为某种错误而导致进入这个状态  
* playing: 播放中，无需多解释  
* paused: 暂停，这个只代表用户行为的暂停。当然播放器在播放的过程中，还有因为不能正常播放而显示出类似“暂停”的状态，统一归为waiting  
* waiting: 进入这个状态有很多原因。一个主要的原因就是等待数据。  


状态与行为的一致性：将状态的改变与对象行为绑定在一起，避免出现状态不能表示当前行为的情况。  
比如暂停操作：可以有两个实现  
* 方法一：（用户）行为触发  
  1.将播放器暂停（行为）  
  2.更新状态到暂停  
* 方法二：(程序)状态触发  
  1.更新状态到暂停（状态）  
  2.将播放器暂停  
错误的例子：单纯的将播放器的状态设置为started, 而没有绑定到播放器的行为上。这样这个状态就无法真实表现出播放当前的实际行为。  


Todo:
=====
Finish！使用固定的Buffer数量，而不是生成N个  
Finish！改用RunLoopSource驱动  
Finish！（NSURLConnection本身就支持）支持网络和本地数据  
Finish！处理正常播放结束  
暂停时，下载进度正常更新  
添加使用BTPlayerItem协议的对象  
支持CBR格式  
统一数据类型的使用  
正常播放结束，点击播放还可以继续播放  
可以设置最小缓冲时间，等待网络数据返回时，不能一有数据就播放，需要多缓冲一会儿再播放，，否会出现播一点，停一下  
用抛异常的方式来处理，代替检查OSStatus  
可以把FileStream和AudioQueue相关的一些操作，封闭到FileStream里去。  
对外接口设计参考AVAudioPlayer  
实现类似AVQueuePlayer这样的连续的播放器，参考对外接口  
参考工程里的PDF文档，确认现有计算播放时间方法的准备性  
BTAudioRequest 内部实现可以由ASIHTTPRequest来代替，功能会更强大，但是对本地文件的支持可能会有问题。  
AudioSession中断，锁屏显示图片  
Check支持更多类型的音频文件   
支持播放列表，预先加载下一个音频的数据  
代码中各处的TODO  
对比原来的播放器的每个参数的设置，和功能点，确保新播放器能够完成达到老播放器所覆盖的功能点。    

