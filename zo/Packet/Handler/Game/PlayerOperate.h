HANDLER_CLASS(PlayerOperate, 0x14)
{
	Player* player = (Player*)(user->getThePlayer());
	UInt32 chips = 0;
	if (pkt.HasChips())
	{
		chips = pkt.Chips();
	}
	player->onOperateAck(pkt.Opcode(), chips);
}
HANDLER_END(PlayerOperate)
