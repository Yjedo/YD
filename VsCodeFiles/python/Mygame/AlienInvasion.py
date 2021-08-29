# coding=gbk
import sys
import pygame
from Ship import ship
from settings import Settings
class AlienIvasion:
    """������Ϸ��Դ����Ϊ����"""
    def __init__(self):
        """��ʼ����Ϸ��������Ϸ��Դ"""
        pygame.init()
        self.settings=Settings()
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        self.ship=ship(self)
    def run_game(self):
        """��ʼ��Ϸ����ѭ��"""
        while True:
            #���Ӽ��̺�����¼�
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
            #ÿ��ѭ��ʱ��������Ļ
            self.screen.fill(self.settings.bg_color)
            self.ship.blitme()
            #��������Ƶ���Ļ�ɼ�
            pygame.display.flip()
if  __name__=='__main__':
    #������Ϸʵ����������Ϸ
    ai = AlienIvasion()
    ai.run_game()



