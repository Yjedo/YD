auto()
timers.addDailyTask({
    path: '/sdcard/�ű�/openApp.js',
    time: '10:35'
}, task => {
    toastLog("�ѿ�ʼ�ڽ���У԰�򿨣�", + task)
})
var appName = '����У԰';
app = launchApp(appName);
while(!click('����'));
while(!click('������Ϣ�ռ�'));
while(!click('�ύ'));