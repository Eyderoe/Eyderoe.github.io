from pc_work.utils import  *
def getHomeData():
    maxMovielen = len(typelist(3))  # 计算电影数量
    maxRateindex, maxRate = max(enumerate(typelist(5)), key=operator.itemgetter(1))  # 计算评分最高的电影及其索引
    maxRateMovie = typelist(3)[maxRateindex]  # 评分最高的电影
    maxCommentindex, maxComment = max(enumerate(typelist(6)), key=operator.itemgetter(1))  # 计算影评最多的电影及其索引位置
    return maxMovielen,maxRate,maxRateMovie,maxComment

def getEchartType():
    maxMovielen=len(typelist(3)) #电影数量
    ratelist=typelist(5) # 电影评分数组
    return maxMovielen,ratelist
def getEchartRate():
    #Ratelist=typelist(5).map(lambda x: float(x)).values
    Ratelist = typelist(5)
    Ratelist.sort()
    Ratetj = {}
    for i in Ratelist:
        if i in Ratetj:
            Ratetj[i] += 1
        else:
            Ratetj[i] = 1
    print(Ratetj)
    return list(Ratetj.keys()),list(Ratetj.values())
def getTimeData():
    Time_Data=[]
    Rate_Data=[]
    for i in range(250):
        xx=(typelist(8)[i].split('/')[-3].split(' ')[-1]).strip()
        yy=typelist(5)[i]
        if len(xx)<=4:
            Time_Data.append(xx)
            Rate_Data.append(yy)
    Time_Data_int=[int(item) for item in Time_Data]
    Time_Data_int.sort()
    zz = zip(Time_Data, Rate_Data)
    dicc={}
    for i in zz:
        dicc[i[0]]=i[1]
    Time_Data_list={}
    for i in Time_Data_int:
        if i in Time_Data_list:
            Time_Data_list[i]+=1
        else:
            Time_Data_list[i]=1
    zzz=[]
    print(Time_Data_list)
getTimeData()
getHomeData()
getEchartRate()
