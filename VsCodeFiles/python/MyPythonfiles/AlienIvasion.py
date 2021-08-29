# coding=gbk   �������Ϊgbk,�Ա����ʹ������ע�͵�
#######################################################################
#   pythonʵ��С��Ŀ
#  �����������֡�
#   ����:Ҷ��
#   ״̬���Ż���
#######################################################################
import sys
import pygame
import pygame.font
from pygame.sprite import Group
from pygame.sprite import Sprite
from time import sleep

class Settings:
    """������Ϸ�����������֡����������õ���"""
    def __init__(self):
        """��ʼ����Ϸ�ľ�̬����"""
        #��Ļ����
        self.screen_width=1200
        self.screen_height=800
        self.bg_color=(188,92,111)

        #�ɴ�����
        self.ship_speed = 1.0
        self.ship_limit = 3         #������

        #�ӵ�����
        self.bullet_speed = 1.0
        self.bullet_width = 10
        self.bullet_height = 10
        self.bullet_color = (60, 60, 60)
        self.Alienbullet_color = (120, 120, 120)
        self.bullets_allowed = 30           #��������Ļ�ϴ��ڵ�����ӵ���

        #����������
        self.alien_speed = 1.0
        self.fleet_drop_speed = 10
        #�ӿ���Ϸ�����ٶ�
        self.speedup_scale = 1.1
        #�����˷�����ߵ��ٶ�
        self.score_scale = 1.5
        self.initialize_dynamic_settings()

    def initialize_dynamic_settings(self):
        """��ʼ������Ϸ���ж��仯������"""
        self.ship_speed = 1.5
        self.bullet_speed = 3.0
        self.alien_speed = 1.0
        #fleet_direction Ϊ1��ʾ���ң�Ϊ-1��ʾ����
        self.fleet_direction = 1
        #�Ƿ�
        self.alien_points = 50

    def increase_speed(self):
        """����ٶ����ú������˷���"""
        self.ship_speed *= self.speedup_scale
        self.bullet_speed *= self.speedup_scale
        self.alien_speed *= self.speedup_scale
        self.alien_points = int(self.alien_points * self.score_scale)
        print(self.alien_points)


class Ship(Sprite):
    """����ɴ�����"""
    def __init__(self, ai_game):            # ai_gameΪ��ǰAlienIvasionʵ����һ�����ã����ɴ���ʼ����һ���������Ա�ship                                              ��
        """��ʼ���ɴ����������ʼλ��"""      #  ���Է���������Ϸ�е�������Դ��
        super().__init__()
        self.screen=ai_game.screen          # ����Ļ������ship��һ�����ԣ��Ա�ship�е����з����������ɷ�����Ļ
        self.settings = ai_game.settings    # ��settings�ำ��ship��һ�����ԣ�ԭ��ͬ��
        self.screen_rect=ai_game.screen.get_rect()  #ʹ�÷���get_rect������Ļ���ԣ��Ա㽫�ɴ�������Ļ����λ��
        #���طɴ�ͼ�񲢻�ȡ����Ӿ���rect
        self.image=pygame.image.load('D:\myfile\python\Mygame\plane.bmp')   #��ȡ�ɴ�ͼƬ
        self.image=pygame.transform.scale(self.image,(120,120))             #��С��õķɴ�ͼƬ�ߴ�
        self.rect=self.image.get_rect()                                     #���ɴ�ͼƬλ�ø���ship������Ļչʾ������Ϊ�ɴ�
        #����ÿ���µķɴ��������������Ļ�ײ�������
        self.rect.midbottom=self.screen_rect.midbottom
        #�ڷɴ�������x�д洢��С��ֵ
        self.x = float(self.rect.x)
        #�ƶ���־
        self.moving_right = False
        self.moving_left = False

    def update(self):
        """�����ƶ���־�����ɴ�λ��"""
        #���·ɴ�������rect�����xֵ
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.x += self.settings.ship_speed
        if self.moving_left and self.rect.left > 0:
            self.x -= self.settings.ship_speed
        #����self.x����rect����
        self.rect.x = self.x 
    def blitme(self):
        """��ָ��λ�û��Ʒɴ�"""
        self.screen.blit(self.image,self.rect)
    def center_ship(self):
        """�÷ɴ�����Ļ�׶˾���"""
        self.rect.midbottom = self.screen_rect.midbottom
        self.x = float(self.rect.x)
class Button:
    def __init__(self, ai_game, msg):
        """��ʼ����ť������"""
        self.screen = ai_game.screen
        self.screen_rect = self.screen.get_rect()

        #���ð�ť�ĳߴ����������
        self.width, self.height = 200, 50
        self.button_color = (0, 255, 0)
        self.text_color = (255, 255, 255)
        self.font = pygame.font.SysFont(None, 48)

        #���ð�ťrect���󣬲�ʹ�����
        self.rect = pygame.Rect(0, 0, self.width, self.height)
        self.rect.center = self.screen_rect.center

        #��ť�ı�ǩֻ�贴��һ��
        self._prep_msg(msg)

    def _prep_msg(self, msg):
        """��msg��ȾΪͼ�񣬲�ʹ���ڰ�ť�Ͼ���"""
        self.msg_image = self.font.render(msg, True, self.text_color, self.button_color)
        self.msg_image_rect = self.msg_image.get_rect()
        self.msg_image_rect.center = self.rect.center

    def draw_button(self):
        #����һ������ɫ���İ�ť�� �ڻ����ı�
        self.screen.fill(self.button_color, self.rect)
        self.screen.blit(self.msg_image, self.msg_image_rect)

class Bullet(Sprite):
    """����ɴ��������ӵ�����"""
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings 
        self.color = self.settings.bullet_color

        #�ڣ�0��0��������һ����ʾ�ӵ��ľ��Σ���������ȷ��λ��
        self.rect = pygame.Rect(0, 0, self.settings.bullet_width,self.settings.bullet_height)
        self.rect.midtop = ai_game.ship.rect.midtop

        #������С����ʾ���ӵ���λ��
        self.y = float(self.rect.y)

    def update(self):
        """�����ƶ��ӵ�"""
        # ���±�ʾ�ӵ�λ�õ�С��ֵ
        self.y -=self.settings.bullet_speed
        #���±�ʾ�ӵ���rect��λ��
        self.rect.y = self.y

    def draw_bullet(self):
        """����Ļ�ϻ����ӵ�"""
        pygame.draw.rect(self.screen, self.color, self.rect)

class Alien(Sprite):
    """��ʾ���������˵���"""
    def __init__(self, ai_game):
        """��ʼ�������˲��������ʼλ��"""
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings

        #����������ͼ��������rect����
        self.image = pygame.image.load("D:\myfile\python\Mygame\Alien.bmp")
        self.image=pygame.transform.scale(self.image,(50,50))    
        self.rect = self.image.get_rect()

        #ÿ�����������������Ļ���ϽǸ���
        self.rect.x = self.rect.width 
        self.rect.y = self.rect.height 

        #���������˵ľ�ȷˮƽλ��
        self.x = float(self.rect.x)
        #�����˵��ӵ�

    def update(self):
        """����������ƶ�������"""
        self.x += (self.settings.alien_speed*self.settings.fleet_direction)
        self.rect.x = self.x

    def check_edges(self):
        """���������λ����Ļ��Ե���ͷ���true"""
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right or self.rect.left <= 0:
            return True 
   
class AlienBullet(Sprite):
    """������������������ӵ�����"""
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings 
        self.color = self.settings.Alienbullet_color

        self.rect = pygame.Rect(0, 0, self.settings.bullet_width,self.settings.bullet_height)
        self.rect.midtop = ai_game.alien.rect.midtop

    def downdate(self):
        self.y += self.settings.bullet_speed
        self.rect.y = self.y

    def draw_bullet(self):
        pygame.draw.rect(self.screen, self.color, self.rect)

class GameStats:
    """������Ϸ��ͳ����Ϣ"""
    def __init__(self, ai_game):
        """��ʼ��ͳ����Ϣ"""
        self.settings =ai_game.settings
        self.reset_stats()
        #��Ϸ������ʱ���ڻ״̬
        self.game_active = False
        #�κ�����¶���Ӧ������ߵ÷�
        self.high_score = 0

    def reset_stats(self):
        """��ʼ������Ϸ�����ڼ���ܱ仯��ͳ����Ϣ"""
        self.ships_left = self.settings.ship_limit
        self.score = 0
        self.level = 1

class Scoreboard:
    """��ʾ�÷���Ϣ����"""
    def __init__(self, ai_game):
        """��ʼ����ʾ�÷��漰������"""
        self.ai_game = ai_game
        self.screen = ai_game.screen
        self.screen_rect = self.screen.get_rect()
        self.settings = ai_game.settings
        self.stats = ai_game.stats
        #��ʾ�÷���Ϣʱʹ�õ���������
        self.text_color = (30,30,30)
        self.font = pygame.font.SysFont(None, 48)
        #׼����ʼ��ߵ÷ֺ͵�ǰ�÷�ͼ��
        self.prep_score()
        self.prep_high_score()
        self.prep_level()
        self.prep_ships()

    def prep_ships(self):
        """��ʾ�����¶����ҷɴ�"""
        self.ships = Group()
        for ship_number in range(self.stats.ships_left):
            ship = Ship(self.ai_game)
            ship.rect.x = 10 + ship_number *ship.rect.width
            ship.rect.y = 10
            self.ships.add(ship)

    def prep_level(self):
        """���ȼ�ת��Ϊ��Ⱦ��ͼ��"""
        level_str = str(self.stats.level)
        self.level_image = self.font.render(level_str, True, self.text_color, self.settings.bg_color)
        #���ȼ����ڵ÷��·�
        self.level_rect = self.level_image.get_rect()
        self.level_rect.right = self.score_rect.right
        self.level_rect.top = self.score_rect.bottom + 10
    
    def prep_high_score(self):
        """����ߵ÷�ת��Ϊ��Ⱦ��ͼ��"""
        high_score = round(self.stats.high_score, -1)
        high_score_str = "{:,}".format(high_score)
        self.high_score_image = self.font.render(high_score_str, True, self.text_color, self.settings.bg_color)
        #����ߵ÷ַ�����Ļ��������
        self.high_score_rect = self.high_score_image.get_rect()
        self.high_score_rect.centerx = self.screen_rect.centerx
        self.high_score_rect.top = self.score_rect.top

    def prep_score(self):
        """���÷�ת��Ϊһ����Ⱦ��ͼ��"""
        rounded_score = round(self.stats.score, -1)
        score_str = "{:,}".format(rounded_score)
        self.score_image = self.font.render(score_str, True, self.text_color, self.settings.bg_color)
        #����Ļ���Ͻ���ʾ�÷�
        self.score_rect = self.score_image.get_rect()
        self.score_rect.right = self.screen_rect.right - 20
        self.score_rect.top = 20
    
    def check_high_score(self):
        """����Ƿ�������µ���ߵ÷�"""
        if self.stats.score > self.stats.high_score:
            self.stats.high_score = self.stats.score
            self.prep_high_score()
    
    def show_score(self):
        """����Ļ����ʾ�÷ֺ͵ȼ������µķɴ���"""
        self.screen.blit(self.score_image, self.score_rect)
        self.screen.blit(self.high_score_image, self.high_score_rect)
        self.screen.blit(self.level_image, self.level_rect)
        self.ships.draw(self.screen)

class AlienIvasion:
    """������Ϸ��Դ����Ϊ����"""
    def __init__(self):
        """��ʼ����Ϸ��������Ϸ��Դ"""
        pygame.init()
        self.settings=Settings()
        self.screen = pygame.display.set_mode((0, 0),pygame.FULLSCREEN)
        self.settings.screen_width = self.screen.get_rect().width
        self.settings.sceen_height = self.screen.get_rect().height
        self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
        pygame.display.set_caption("Alien Invasion")
        #����һ�����ڴ�����Ϸͳ����Ϣ��ʵ��
        #�������Ƿ���
        self.stats = GameStats(self)
        self.sb = Scoreboard(self)
        #����һ���ɴ�ʵ��
        self.ship=Ship(self)
        #�����ӵ�ʵ��
        self.bullets = pygame.sprite.Group()
        #����������ʵ��
        self.aliens = pygame.sprite.Group()
        self.alien = Alien(self)
        self._create_fleet()
        #����play��ť
        self.play_button = Button(self, "Play")

    def _ship_hit(self):
        """��Ӧ�ɴ���������ײ��"""
        if self.stats.ships_left > 0:
            #��ships_left��1�����¼Ƿ���
            self.stats.ships_left -= 1
            self.sb.prep_ships()
            #������µ������˺��ӵ�
            self.aliens.empty()
            self.bullets.empty()
            #����һȺ�µ������ˣ������ɴ��ŵ���Ļ�׶˵�����
            self._create_fleet()
            self.ship.center_ship()
             #��ͣ
            sleep(0.5)
        else:
            self.stats.game_active = False

    def _check_aliens_bottom(self):
        """����Ƿ��������˵�������Ļ�׶�"""
        screen_rect = self.screen.get_rect()
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= screen_rect.bottom:
                #��ɴ���ײ��һ������
                self._ship_hit()
                break

    def _check_fleet_edges(self):
        """�������˵�����Ļ��Եʱ����ȡ��Ӧ��ʩ"""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    def _change_fleet_direction(self):
        """����Ⱥ���������Ʋ��ı����ǵķ���"""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= -1

    def _create_alien(self,alien_number, row_number):
         #����һ�������˲�������뵱ǰ��
        alien =Alien(self)
        alien_width, alien_height = alien.rect.size 
        alien_width = alien.rect.width
        alien.x = alien_width + 2*alien_width*alien_number
        alien.rect.x = alien.x
        alien.rect.y = alien.rect.height + 2*alien.rect.height*row_number
        self.aliens.add(alien)

    def _create_fleet(self):
        """����������Ⱥ"""
        #����һ�������˲�����һ�п������ɶ���������
        #�����˵ļ��Ϊ�����˵Ŀ��
        alien = Alien(self)
        alien_width, alien_height = alien.rect.size 
        available_space_x = self.settings.screen_width - (2*alien_width)
        number_aliens_x = available_space_x // (2*alien_width)
        #������Ļ�������ɶ���������
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height - (3*alien_height) - ship_height)
        number_rows = available_space_y // (2*alien_height)
        #������������Ⱥ
        for row_number in range(number_rows):
            for alien_number in range(number_aliens_x):
                self._create_alien(alien_number, row_number)

    def _fire_bullet(self):
        """����һ���ӵ�������������bullets��"""
        if len(self.bullets) < self.settings.bullets_allowed:
            new_bullet = Bullet(self)
            self.bullets.add(new_bullet)

    def _update_bullets(self):
        """�����ӵ���λ�ò�ɾ����ʧ���ӵ�"""
        #�����ӵ���λ��
        self.bullets.update()
        #ɾ����ʧ���ӵ�
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <= 0:
                self.bullets.remove(bullet)
        self._check_bullet_alien_collisions()

    def _check_bullet_alien_collisions(self):
        #����Ƿ����ӵ�������������
        #����ǣ���ɾ����Ӧ���ӵ���������
        collisions = pygame.sprite.groupcollide(self.bullets, self.aliens, True, True)
        if collisions :
            for aliens in collisions.values():
                self.stats.score += self.settings.alien_points * len(aliens)
                self.sb.prep_score()
                self.sb.check_high_score()
        if not self.aliens:
            #ɾ�����е��ӵ����´���һȺ������
            self.bullets.empty()
            self._create_fleet()
            self.settings.increase_speed()
            #��ߵȼ�
            self.stats.level += 1
            self.sb.prep_level()

    def _check_keydown_events(self,event):
        """��Ӧ����"""
        if event.key == pygame.K_RIGHT:
             #�����ƶ��ɴ�
            self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = True
        elif event.key ==pygame.K_q:
            sys.exit()
        elif event.key == pygame.K_SPACE:
            self._fire_bullet()

    def _check_keyup_events(self,event):
        """��Ӧ�ɿ�"""
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False

    def _check_events(self):
        """��Ӧ����������¼�"""
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
                    self._check_keyup_events(event)
            elif event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                self._check_play_button(mouse_pos)

    def _check_play_button(self, mouse_pos):
        """����ҵ��Play��ťʱ��ʼ����Ϸ"""
        button_clicked = self.play_button.rect.collidepoint(mouse_pos)

        if button_clicked and not self.stats.game_active:
            """������Ϸͳ����Ϣ"""
            self.settings.initialize_dynamic_settings()
            self.stats.reset_stats()
            self.stats.game_active = True
            self.sb.prep_score()
            self.sb.prep_level()
            self.sb.prep_ships()
            #������µ������˺��ӵ�
            self.aliens.empty()
            self.bullets.empty()
            #����һȺ�µ������˲��÷ɴ�����
            self._create_fleet()
            self.ship.center_ship()

    def _update_screen(self):
        """������Ļ�ϵ�ͼ�񣬲��л�������Ļ"""
        self.screen.fill(self.settings.bg_color)
        self.ship.blitme()
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
        self.aliens.draw(self.screen)
        #��ʾ�÷�
        self.sb.show_score()
        #�����Ϸ���ڷǻ״̬���ͻ���Play��ť
        if not self.stats.game_active:
            self.play_button.draw_button()
        #��������Ƶ���Ļ�ɼ�
        pygame.display.flip()

    def _update_aliens(self):
        """"
        ����Ƿ���������λ����Ļ��Ե
        ��������Ⱥ�����˵�λ��
        """
        self._check_fleet_edges()
        self.aliens.update()
        #��������˺ͷɴ�֮�����ײ
        if pygame.sprite.spritecollideany(self.ship, self.aliens):
            self._ship_hit()
        #����Ƿ��������˵�������Ļ�׶�
        self._check_aliens_bottom()

    def run_game(self):
        """��ʼ��Ϸ����ѭ��"""
        while True:
            self._check_events()
            if self.stats.game_active:
                self.ship.update()
                self._update_bullets()
                self._update_aliens()
            self._update_screen()   

if  __name__=='__main__':
    #������Ϸʵ����������Ϸ
    ai = AlienIvasion()
    ai.run_game()

# ��ѧ�ջ�AlienIvasion��һ�����ࣨ�൱�ڴ���Ϸ��������ship��settings, Buttled���൱����������һ���֣���������AlienIvasion�ֲ��ǰ�����ϵ
# �������������֫��ͷ֮��Ĺ�ϵһ��. ����֮��Ҳ�����Ÿ��ֹ�ϵ
# ����һ����Ŀ����������һ����������һ�������Ŀ��


